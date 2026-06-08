import time
import math
import traceback
import numpy as np
import pydub.utils
import sounddevice as sd

import time
import math
import os
import random
import sys
import atexit
import signal
import json
import base64
import pickle
import zipfile
import shutil
import traceback
from datetime import datetime

# Attempt to load third party modules globally to avoid loop latency
try:
    import xmltodict
    import sounddevice as sd
    from pydub.scipy_effects import low_pass_filter, high_pass_filter
except ImportError:
    pass # Will be caught by specific functions if missing

import os
import time
import math
import random
import traceback
import pydub
import sounddevice as sd
from mutagen.mp3 import MP3
from mutagen.wave import WAVE
from pyaudio import PyAudio

os.makedirs(".\\logs\\errors", exist_ok=True)

class log:
    data = []
    hasLogged = False
    dateString = ""
    timeString = ""
    profile = True

    doPrint = False
    debug = True
    
    @staticmethod
    def crash(*strff):
        for strf in strff:
            if log.doPrint or log.debug:
                print(str(strf))
            if not log.hasLogged:
                log.data.append([pytools.clock.getDateTime(), str(strf), str(traceback.format_stack())])
                error_keywords = ("Traceback", "Error", "error", "Failed", "failed", "Unable", "unable", "WARNING", "Warning", "warning")
                if any(kw in str(strf) for kw in error_keywords):
                    dateArray = pytools.clock.getDateTime()
                    if log.dateString == "":
                        log.dateString = f"{dateArray[0]}-{dateArray[1]}-{dateArray[2]}"
                        log.timeString = f"{dateArray[3]}.{dateArray[4]}.{dateArray[5]}_{str(time.time() * 100000).split('.')[0]}"
                    
                    log_dir = f".\\logs\\errors\\{log.dateString}"
                    os.makedirs(log_dir, exist_ok=True)
                    
                    for data in log.data:
                        msg_dateArray = data[0]
                        message = str(data[1])
                        callStack = str(data[2])
                        # pytools.IO.appendFile(f"{log_dir}\\event_{log.timeString}.log", f"\n{msg_dateArray} :;: {message} :;: {callStack.replace(chr(10), '    \n\t')}")
                    log.hasLogged = True
            else:
                dateArray = pytools.clock.getDateTime()
                log_dir = f".\\logs\\errors\\{log.dateString}"
                # pytools.IO.appendFile(f"{log_dir}\\event_{log.timeString}.log", 
                #                       f"\n{dateArray} :;: {strf} :;: {str(traceback.format_stack()).replace(chr(10), '    \n\t')}")

    @staticmethod
    def doEndDump():
        dateArray = pytools.clock.getDateTime()
        if log.dateString == "":
            log.dateString = f"{dateArray[0]}-{dateArray[1]}-{dateArray[2]}"
            log.timeString = f"{dateArray[3]}.{dateArray[4]}.{dateArray[5]}_{str(time.time() * 100000).split('.')[0]}"
        
        os.makedirs(".\\logs\\sounds", exist_ok=True)
        
        if dateArray[3] == 3:
            sound_log_path = f".\\logs\\sounds\\{log.dateString}.log"
            if not os.path.exists(sound_log_path):
                pytools.IO.saveFile(sound_log_path, "no_data")
                soundData = ""
                
                today_dir = ".\\logs\\today"
                if os.path.exists(today_dir):
                    for n in os.listdir(today_dir):
                        logData = pytools.IO.getFile(os.path.join(today_dir, n))
                        if isinstance(logData, str):
                            for data in logData.split("\n"):
                                if "Playing sound of path" in data:
                                    last_line = logData.split("\n")[-1]
                                    try:
                                        time_arr = [eval(i) for i in last_line.split(" :;:")[0].strip('][').split(', ')]
                                        soundData += f"{data} ;;; Sound exited at time {time_arr}\n"
                                    except Exception:
                                        pass
                
                if pytools.IO.getFile(sound_log_path) == "no_data":
                    pytools.IO.saveFile(sound_log_path, soundData)
                    # Use native Python os.remove instead of os.system shell call
                    if os.path.exists(today_dir):
                        for f in os.listdir(today_dir):
                            try:
                                os.remove(os.path.join(today_dir, f))
                            except:
                                pass

        os.makedirs(".\\logs\\today", exist_ok=True)

def printDebug(strf):
    log.crash(strf)
   
def exit_handler():
    log.crash("Audio Engine Instance Has Finished.")
    log.doEndDump()

def kill_handler(*args):
    sys.exit(0)

def exception_handler(exc_type, exc_value, exc_traceback):
    if issubclass(exc_type, KeyboardInterrupt):
        sys.__excepthook__(exc_type, exc_value, exc_traceback)
        return

    log.crash("Uncaught exception")
    log.crash('Type:', exc_type)
    log.crash('Value:', exc_value)
    log.crash('Traceback:', traceback.format_exception((exc_type, exc_value, exc_traceback)))

if __name__ == '__main__':
    sys.excepthook = exception_handler

def getFlag(flagName):
    flag_path = f".\\{flagName}.derp"
    if os.path.exists(flag_path):
        try:
            return float(pytools.IO.getFile(flag_path))
        except:
            return True
    return False

class pytools:
    class clock:
        @staticmethod
        def getDateTime(utc=False):
            # Optimized to avoid heavy string conversions and splits
            daten = datetime.utcnow() if utc else datetime.now()
            return [daten.year, daten.month, daten.day, daten.hour, daten.minute, daten.second]
    
    class cipher:  
        @staticmethod
        def base64_encode(s):
            return base64.standard_b64encode(bytes(s, encoding="utf-8")).decode("utf-8").replace("=", "?")
            
        @staticmethod
        def base64_decode(s: str):
            return base64.standard_b64decode(s.replace("?", "=")).decode("utf-8")
    
    class IO:
        @staticmethod
        def getJson(path, doPrint=True):
            try:
                with open(path, "r") as file:
                    return json.load(file)
            except Exception as e:
                if doPrint:
                    log.crash(f"Unexpected error: " + traceback.format_exc())
                return 1
        
        @staticmethod
        def getXml(path, doPrint=True):
            file_data = pytools.IO.getFile(path, doPrint=doPrint)
            return xmltodict.parse(file_data) if file_data != 1 else 1
        
        @staticmethod
        def saveXml(path, doPrint=True):
            pass

        @staticmethod
        def saveJson(path, jsonData):
            try:
                with open(path, "w") as file:
                    json.dump(jsonData, file)
                return 0
            except Exception:
                log.crash(f"Unexpected error: {traceback.format_exc()}")
                return 1

        @staticmethod
        def getFile(path, doPrint=True):
            try:
                with open(path, "r") as file:
                    return file.read()
            except Exception:
                if doPrint:
                    log.crash(f"Unexpected error: {traceback.format_exc()}")
                return 1
        
        @staticmethod
        def getBytes(path, doPrint=True):
            try:
                with open(path, "rb") as file:
                    return file.read()
            except Exception:
                if doPrint:
                    log.crash(f"Unexpected error: {traceback.format_exc()}")
                return 1

        @staticmethod
        def saveFile(path, jsonData):
            try:
                with open(path, "w") as file:
                    file.write(jsonData)
                return 0
            except Exception:
                log.crash(f"Unexpected error: {traceback.format_exc()}")
                return 1
        
        @staticmethod
        def saveBytes(path, jsonData):
            try:
                with open(path, "wb") as file:
                    file.write(jsonData)
                return 0
            except Exception:
                log.crash(f"Unexpected error: {traceback.format_exc()}")
                return 1

        @staticmethod
        def saveList(path, lst):
            try:
                with open(path, "wb") as file:
                    pickle.dump(lst, file)
                return 0
            except Exception:
                log.crash(f"Unexpected error: {traceback.format_exc()}")
                return 1

        @staticmethod
        def getList(path, doPrint=True):
            try:
                with open(path, "rb") as file:
                    return [[], pickle.load(file)]
            except Exception:
                if doPrint:
                    log.crash(f"Unexpected error: {traceback.format_exc()}")
                return [[], 1]

        @staticmethod
        def appendFile(path, jsonData):
            try:
                with open(path, "a") as file:
                    file.write(jsonData)
                return 0
            except Exception:
                log.crash(f"Unexpected error: {traceback.format_exc()}")
                return 1
        
        @staticmethod
        def unpack(path, outDir):
            try:
                with zipfile.ZipFile(path, 'r') as zip_ref:
                    log.crash(str(zip_ref.printdir()))
                    log.crash('Extracting zip resources...')
                    zip_ref.extractall(outDir)
                    log.crash("Done.")
            except Exception as erro:
                log.crash("Could not unpack zip file.")
                log.crash(erro)

        @staticmethod
        def pack(path, dir):
            shutil.make_archive(path, 'zip', dir)

if __name__ == '__main__':
    atexit.register(exit_handler)
    signal.signal(signal.SIGINT, kill_handler)
    signal.signal(signal.SIGTERM, kill_handler)

class info:
    def __init__(self):
        self.uuid = random.random()
    
    globalSoundStart = False
    loopSync = {}
    skipParodyCheck = False
    timeingInfo = 0
    
def intenseSleep(i):
    # Preserved exactly for audio spin lock timing
    x = time.perf_counter() + i
    while time.perf_counter() < x:
        pass

class thread_handler:
    def __init__(self, obj, args=()):
        self.obj = obj
        self.args = args
        
    def run(self):
        try:
            self.obj(*self.args)
        except Exception:
            log.crash(traceback.format_exc())
        log.crash(f"Thread {self.obj} has exited.")

class obj:
    activeSounds = {}

testEvent = {
    "events": [
        {
            "path": ".\\sound\\assets\\dnwbella.mp3",
            "volume": 10,
            "speed": 1.3,
            "channel": "fireplace",
            "effects": [{"type": "lowpass", "freqency": 1000, "db": 20}]
        },
        {
            "path": ".\\sound\\assets\\dnwbella.mp3",
            "volume": 10,
            "speed": 1.3,
            "channel": "clock",
            "effects": [{"type": "lowpass", "freqency": 1000, "db": 20}]
        },
        {
            "path": ".\\sound\\assets\\dnwbella.mp3",
            "volume": 10,
            "speed": 1.3,
            "channel": "window",
            "effects": [{"type": "lowpass", "freqency": 1000, "db": 20}]
        },
    ],
    "wait": True
}

class globals:
    bufferSize = 8
    chunkSize = 2048
    speakers = {}
    maxCount = 100
    close = False
    maxStreamDelay = 0

if os.path.exists(".\\soundOutputs.json"):
    globals.speakers = pytools.IO.getJson(".\\soundOutputs.json")
elif os.path.exists("..\\soundOutputs.json"):
    globals.speakers = pytools.IO.getJson("..\\soundOutputs.json")
    
class tools:
    @staticmethod
    def setOutputs(noSleep=False):
        if os.path.exists(".\\soundOutputs.json"):
            globals.speakers = pytools.IO.getJson(".\\soundOutputs.json")
        elif os.path.exists("..\\soundOutputs.json"):
            globals.speakers = pytools.IO.getJson("..\\soundOutputs.json")
            
        try:
            devices = sd.query_devices()
            for channel in globals.speakers:
                deviceIndex = None
                for n in devices:
                    if not noSleep:
                        time.sleep(0.1)
                    if globals.speakers[channel][0] == n["name"]:
                        if globals.speakers[channel][1] == "MME" and n["hostapi"] == 0:
                            deviceIndex = n["index"]
                            break
                        if globals.speakers[channel][1] == "WDM-KS" and n["hostapi"] == 4:
                            deviceIndex = n["index"]
                            break
                if deviceIndex is not None:
                    globals.speakers[channel].append(deviceIndex)
            
            pytools.IO.saveJson("speakerSets.json", {"speakers": globals.speakers})
        except Exception:
            log.crash(traceback.format_exc())
    
class audioEffects:
    @staticmethod
    def lowPass(data, frequency, db=24):
        if data is not False and not isinstance(data, float):
            return low_pass_filter(data, frequency, order=db)
        return False
    
    @staticmethod
    def highPass(data, frequency, db=24):
        if data is not False and not isinstance(data, float):
            return high_pass_filter(data, frequency, order=db)
        return False

# Assuming info(), globals, log, intenseSleep, and printDebug are defined elsewhere in your project
_info_instance = info()

class stream:
    def __init__(self, seg, speed, device, duration, soundIndex, lastPlayed, startPlayed, bufferSize, balence, startDelay=0):
        self.channels = seg.channels
        self.frame_rate = seg.frame_rate
        self.sample_width = seg.sample_width
        self.speed = speed
        self.device = device
        self.startDelay = startDelay
        self.duration = duration
        self.soundIndex = soundIndex
        self.lastPlayed = lastPlayed
        self.isDone = False
        self.startPlayed = startPlayed
        self.bufferSize = bufferSize
        
        # 1. PRECOMPUTE CONSTANTS: Avoid doing this math inside the audio loop
        self.normalize_factor = 1 << (8 * self.sample_width - 1)
        self.chunk_size_sec = globals.chunkSize / 1000.0
        self.duration_micro = self.duration * 1000000
        self.end_time_threshold = self.duration_micro + 5000000 # pre-calculated threshold
        
        self.chunksActive = pydub.utils.make_chunks(seg, globals.chunkSize)
        self.chunks = False
        
        # Shared info state
        self._info = _info_instance
        
        print(f"stream_start_delay: {self.startDelay}")

    def _audio_to_numpy(self, audio):
        """Helper method. Prevents redefining functions inside a loop."""
        arr = np.array(audio.get_array_of_samples(), dtype=np.float32)
        # Uses the precomputed normalize_factor for speed
        return arr.reshape((-1, self.channels)) / self.normalize_factor

    def run(self):
        try:
            self.audioStream.start()
            self.i = 0
            self.delayStart = time.perf_counter()
            self.startPlayed = time.time() * 1000000
            
            # Update global delay directly
            if (self.startDelay + self.duration) >= globals.maxStreamDelay:
                globals.maxStreamDelay = (self.startDelay + self.duration)
            
            # Use the precomputed threshold in the loop condition
            while ((self.startPlayed + self.end_time_threshold) > (time.time() * 1000000)) or (not isinstance(self.chunksActive, bool)):
                
                # Hand over chunks
                if not isinstance(self.chunksActive, bool):
                    self.chunks = self.chunksActive
                    self.chunksActive = True
                
                if isinstance(self.chunks, list):
                    # Replace list(map(...)) with a standard, fast for-loop
                    for chunk in self.chunks:
                        if not chunk:
                            if log.debug:
                                log.crash("Chunked Buffer Overflow!")
                            continue
                        
                        if self.i == 0:
                            if self._info.globalSoundStart is not False:
                                self._info.globalSoundStart = time.perf_counter()
                            self.startPlayed = time.time() * 1000000
                            
                        timeingInfo = (self._info.globalSoundStart + self.i) - time.perf_counter()

                        if timeingInfo > 0.01:
                            intenseSleep(timeingInfo)
                            self.audioStream.write(self._audio_to_numpy(chunk))
                        elif timeingInfo < -0.01:
                            if timeingInfo > -self.chunk_size_sec:
                                sampleDuration = chunk[0:100].duration_seconds / 100.0
                                skip_samples = int(abs(timeingInfo) / sampleDuration)
                                self.audioStream.write(self._audio_to_numpy(chunk[skip_samples:]))
                        else:
                            self.audioStream.write(self._audio_to_numpy(chunk))
                            
                        self.i += (chunk.duration_seconds / self.speed)
                else:
                    if log.debug:
                        log.crash("Buffer Overflow!")
                    time.sleep(0.1)

        except Exception:
            printDebug(traceback.format_exc())

        finally:
            # The 'finally' block ensures cleanup happens quickly and avoids duplicating code
            time.sleep(globals.bufferSize)
            if hasattr(self, 'audioStream') and self.audioStream:
                self.audioStream.stop()
                self.audioStream.close()

            if (self.startDelay + self.duration) >= globals.maxStreamDelay:
                globals.close = True
            self.isDone = True
            
class soundEvent:
    # Class-level variables
    doneLoading = False
    data = False
    itsStream = False
    Iinfo = None # Assuming info() is defined elsewhere, initialized in __init__ if needed
    index = 0
    lastPlayed = 0
    muteState = False

    def __init__(self, path, volume, speed, channel, effects, balence, muteOptions=False, startDelay=0):
        self.path = path
        self.filename = path.split("\\")[-1] # Cache filename for faster lookups
        
        self.uuid = random.random()
        while self.uuid in obj.activeSounds:
            self.uuid = random.random()
            
        self.volume = volume
        self.speed = speed
        self.balence = balence
        self.channel = channel
        self.startDelay = startDelay
        self.effects = effects
        
        # Precalculate static volume shift to save CPU cycles in the run loop
        self.volume_shift_db = 20 * math.log(self.volume / 100, 10) if self.volume > 0 else -120

        if ".mp3" in path:
            self.duration = float(MP3(path).info.length) / speed
        else:
            self.duration = float(WAVE(path).info.length) / speed

        if muteOptions:
            self.muteFlag = muteOptions["flag_name"]
            self.booleanValueToMuteOn = muteOptions["do_mute"]
            self.doMuteFade = muteOptions["fade"]
            
            flag_val = getFlag(self.muteFlag)
            if flag_val and self.booleanValueToMuteOn:
                self.muteState = (1 - flag_val) * 99
            elif (not flag_val) and (not self.booleanValueToMuteOn):
                self.muteState = 0
            else:
                if self.booleanValueToMuteOn:
                    self.muteState = (1 - flag_val) * 99
                else:
                    self.muteState = flag_val * 99
            
            self.previousMuteState = self.muteState
        else:
            self.muteFlag = "no_flag"
            self.booleanValueToMuteOn = True
            self.doMuteFade = False
            self.muteState = False
            
        self.Iinfo = info() # Initialize here to avoid class-level pollution
        
    def initStream(self):
        try:
            deviceIndex = None
            try:
                try:
                    globals.speakers = pytools.IO.getJson("speakerSets.json", doPrint=False)["speakers"]
                except Exception:
                    log.crash("Unable to load speakerSets file. Reloading...")
                    errorTic = 0
                    while errorTic < 10:
                        try:
                            globals.speakers = pytools.IO.getJson("speakerSets.json", doPrint=False)["speakers"]
                            break
                        except Exception:
                            log.crash("Unable to load speakerSets file. Reloading...")
                        time.sleep(1)
                        errorTic += 1
                        
                printDebug(self.channel)
                deviceIndex = globals.speakers[self.channel][2]
                
                if globals.speakers[self.channel][0] != sd.query_devices()[deviceIndex]["name"]:
                    devices = sd.query_devices()
                    return
                
            except Exception:
                devices = sd.query_devices()
                for n in devices:
                    time.sleep(0.1)
                    if globals.speakers[self.channel][0] == n["name"]:
                        if globals.speakers[self.channel][1] == "MME" and n["hostapi"] == 0:
                            deviceIndex = n["index"]
                            break
                        if globals.speakers[self.channel][1] == "WDM-KS" and n["hostapi"] == 4:
                            deviceIndex = n["index"]
                            break
                if deviceIndex is not None:
                    globals.speakers[self.channel].append(deviceIndex)
                    pytools.IO.saveJson("speakerSets.json", {"speakers": globals.speakers})
            
            self.itsStream = stream(
                self.data, self.speed, deviceIndex, self.duration, 
                self.index, self.lastPlayed, round(time.time() * 1000000), 
                globals.bufferSize, self.balence, startDelay=self.startDelay
            )
            
            time.sleep(1)
            
            self.itsStream.audioStream = sd.OutputStream(
                blocksize=2048,
                channels=self.itsStream.channels,
                device=self.itsStream.device,
                samplerate=int(self.itsStream.frame_rate * self.speed),
            )
            
        except Exception:
            printDebug(traceback.format_exc())
            
        self.doneLoading = True
    
    def load(self, index):
        self.index = index
        
        if math.floor((self.duration / globals.bufferSize) + 1) >= index:
            lastModif = os.path.getmtime(self.path)
            cache_path = f".\\.audiocache\\{self.filename}-cache.{index * globals.bufferSize}.pyl"
            
            if os.path.exists(cache_path):
                printDebug(f"loading cached index {index}...")
                cachedData = pytools.IO.getList(cache_path)[1]
                self.data = cachedData[0]
                if cachedData[1] != lastModif:
                    printDebug(f"not cached! loading index {index}...")
                    self.data = pydub.AudioSegment.from_file(file=self.path.replace("\t", "\\t"), format="mp3", start_second=index * globals.bufferSize, duration=globals.bufferSize)
                    pytools.IO.saveList(cache_path, [self.data, lastModif])
            else:
                printDebug(f"not cached! loading index {index}...")
                self.data = pydub.AudioSegment.from_file(file=self.path.replace("\t", "\\t"), format="mp3", start_second=index * globals.bufferSize, duration=globals.bufferSize)
                pytools.IO.saveList(cache_path, [self.data, lastModif])
        else:
            self.data = False
            
        bal = False
        
        if self.muteFlag != "no_flag":
            flag_val = getFlag(self.muteFlag)
            if flag_val and self.booleanValueToMuteOn:
                self.muteState = (1 - flag_val) * 99
            elif (not flag_val) and (not self.booleanValueToMuteOn):
                self.muteState = 0
            else:
                if self.booleanValueToMuteOn:
                    self.muteState = (1 - flag_val) * 99
                else:
                    self.muteState = flag_val * 99
                
            mute_db = 20 * math.log((self.muteState + 0.01) / 100, 10)
            
            if self.muteState != self.previousMuteState:
                prev_mute_db = 20 * math.log((self.previousMuteState + 0.01) / 100, 10)
                if self.doMuteFade:
                    fade_dur = globals.chunkSize if globals.chunkSize < 4096 else 4096
                    self.data = self.data.fade(from_gain=prev_mute_db, start=0, duration=fade_dur)
                    self.data = self.data.fade(to_gain=mute_db, start=0, duration=fade_dur)
                else:
                    self.data = self.data + mute_db
                self.previousMuteState = self.muteState
            else:
                self.data = self.data + mute_db
            
        if self.balence != 0:
            monoSets = self.data.split_to_mono()
            if len(monoSets) == 1:
                monoSets = [monoSets[0], monoSets[0]]
                self.data = pydub.AudioSegment.from_mono_audiosegments(*monoSets)
                
            bal_shift = 20 * math.log((0.01 + 100 - math.fabs(self.balence)) / 100, 10)
            if self.balence < 0:
                monoSets[1] = monoSets[1] + bal_shift
                bal = True
            elif self.balence > 0:
                monoSets[0] = monoSets[0] + bal_shift
                bal = True
        
        if bal:
            self.data = pydub.AudioSegment.from_mono_audiosegments(*monoSets)
    
    def iter(self):
        self.load(self.index + 1)
        
    def handleEffects(self, effect):
        try:
            log.crash(f"{self.data}\t{effect.get('frequency')}\t{effect.get('db')}")
        except Exception:
            pass
            
        try:
            if effect["type"] == "lowpass":
                if "db" in effect:
                    self.data = audioEffects.lowPass(self.data, effect["frequency"], effect["db"])
                else:
                    self.data = audioEffects.lowPass(self.data, effect["frequency"])
                    
            elif effect["type"] == "highpass":
                if "db" in effect:
                    self.data = audioEffects.highPass(self.data, effect["frequency"], effect["db"])
                else:
                    self.data = audioEffects.highPass(self.data, effect["frequency"])
        except Exception:
            log.crash("Could not add effects to sound.")
    
    def handleRun(self):
        try:
            startPlayed = round(time.time() * 1000000)
            obj.activeSounds[self.uuid] = self.filename
            log.crash(f"Playing sound of path {self.path} on the {self.channel} channel at volume {self.volume_shift_db} at {self.speed}x speed...")
            
            justStarted = True
            while ((self.data is not False) or justStarted) and (not self.itsStream.isDone):
                time.sleep(0.05)
                if globals.close or self.itsStream.isDone:
                    print("exit detected.")
                    return
                
                self.iter()
                justStarted = False
                
                # Apply pre-calculated volume shift
                self.data = self.data + self.volume_shift_db
                
                if isinstance(self.data, float) or self.data is False:
                    return
                
                # Optimized effects loop (avoiding map overhead)
                for effect in self.effects:
                    if globals.close:
                        return
                    self.handleEffects(effect)
                
                self.itsStream.chunksActive = pydub.utils.make_chunks(self.data, globals.chunkSize)
                self.lastPlayed = (startPlayed + (self.index * 1000000)) / 1000000
                self.itsStream.lastPlayed = self.lastPlayed
                
                def syncEventKey(idf):
                    return info.loopSync[idf]
                
                try:
                    if (max(info.loopSync, key=syncEventKey) - min(info.loopSync, key=syncEventKey)) < 0.01:
                        info.skipParodyCheck = True
                except Exception:
                    pass
                
                # Spin lock - preserved as requested
                while self.itsStream.chunksActive is not True:
                    if globals.close or self.itsStream.isDone:
                        print("exit detected.")
                        return
                    time.sleep(0.5)
                    
            obj.activeSounds.pop(self.uuid, None)
            
        except Exception:
            printDebug(traceback.format_exc())

import os
import sys
import time
import random
import math
import threading
import copy
import json

# Move expensive library imports to the top level to avoid module-check overhead during loop execution.
# (Assuming these are globally available based on your original script)
import gtts
from mutagen.wave import WAVE
from mutagen.mp3 import MP3

class multiEvent:
    # Class-level variable defaults
    syncEvents = []
    streamThreads = []
    handlerThreads = []

    def __init__(self, eventData):
        log.crash("multiEvent_init_0")
        self.wait = eventData.get("wait")
        self.eventData = eventData
        self.syncEvents = [] 
        
        # Cache file system checks before the loop to prevent repeated I/O calls
        random_sounds_exists = os.path.exists(".\\randomSounds.derp")
        speak_sounds_exists = os.path.exists(".\\speakSounds.derp")
        
        if random_sounds_exists:
            audioList = os.listdir(".\\sound\\assets")
            len_audioList = len(audioList) - 1

        for event in eventData.get("events", []):
            log.crash("multiEvent_init_1")
            time.sleep(0.1)  # Preserved sync sleep
            
            if event.get("volume", 0) > 0.0:
                # Random sounds handling
                if random_sounds_exists:
                    event["path"] = f".\\sound\\assets\\{audioList[random.randint(0, len_audioList)]}"
                    # Fast string 'in' checks instead of chained .find() == -1
                    while ".mp3" not in event["path"] and ".wav" not in event["path"]:
                        time.sleep(0.1)  # Preserved spin lock
                        event["path"] = f".\\sound\\assets\\{audioList[random.randint(0, len_audioList)]}"
                
                # Speak sounds handling
                if speak_sounds_exists:
                    file_name = event["path"].split("\\")[-1]
                    speak_path = f".\\sound\\assets\\speak_troll-{file_name}.wav"
                    
                    if not os.path.exists(speak_path):
                        ln = 1
                        try:
                            if ".mp3" not in event["path"]:
                                audiowave = WAVE(f".\\sound\\assets\\{file_name}")
                                ln = int(audiowave.info.length) + 1
                            else:
                                audiomp3 = MP3(f".\\sound\\assets\\{file_name}")
                                ln = int(audiomp3.info.length) + 1
                        except Exception:
                            pass
                        
                        # Faster string multiplication 
                        text_base = file_name.replace("_", " ").replace(".mp3", "").replace(".wav", "") + " "
                        textf = text_base * (int(ln / len(text_base.split(" "))) + 1)
                        
                        gtts.gTTS(text=textf, lang="en", slow=False).save(speak_path)
                        
                    event["path"] = speak_path
                
                start_delay = event.get("start_delay", 0)
                event["start_delay"] = start_delay
                print(f"start_delay: {start_delay}")
                
                # Parse path once
                clean_path = event["path"].replace("\\working\\", "\\")
                
                if "mute_options" not in event:
                    self.syncEvents.append(soundEvent(
                        clean_path, event["volume"], event["speed"], 
                        event["channel"], event["effects"], event["balence"], 
                        startDelay=start_delay
                    ))
                else:
                    self.syncEvents.append(soundEvent(
                        clean_path, event["volume"], event["speed"], 
                        event["channel"], event["effects"], event["balence"], 
                        muteOptions=event["mute_options"], startDelay=start_delay
                    ))

    def load(self):
        for sound in self.syncEvents:
            time.sleep(0.05) # Preserved sync sleep
            sound.load(0)
            
    def iter(self, event=False, index=False):
        # Using 'is not False' to safely catch '0' index/event values
        if event is not False: 
            if index is not False:
                self.syncEvents[event].load(index)
            else:
                self.syncEvents[event].iter()
        else:
            if index is not False:
                for sound in self.syncEvents:
                    time.sleep(0.05) # Preserved sync sleep
                    sound.load(index)
            else:
                for sound in self.syncEvents:
                    time.sleep(0.05) # Preserved sync sleep
                    sound.iter()
                    
    def process(self, event=False):
        if event is not False:
            target_event = self.syncEvents[event]
            # math.log10 is compiled in C and is significantly faster than math.log(..., 10)
            shift = 20 * math.log10(target_event.volume / 100.0) 
            target_event.data += shift
            for effect in target_event.effects:
                time.sleep(0.05) # Preserved sync sleep
                target_event.handleEffects(effect)
        else:
            for sound in self.syncEvents:
                shift = 20 * math.log10(sound.volume / 100.0)
                sound.data += shift
                time.sleep(0.05) # Preserved sync sleep
                for effect in sound.effects:
                    sound.handleEffects(effect)
        
    def run(self):
        log.crash("running...")
        printDebug(0)
        self.load()
        printDebug(1)
        self.process()
        printDebug(2)
        
        def begin(currentSyncEvents):
            class _inside:
                streamThreads = []
                handlerThreads = []
            
            _info = info()
            _info.globalSoundStart = time.perf_counter() + 3
            
            printDebug(5)
            for sound in currentSyncEvents:
                time.sleep(0.05) # Preserved sync sleep
                printDebug(sound)
                
                sound._info = _info
                sound.itsStream._info = _info
                
                _inside.streamThreads.append(threading.Thread(target=thread_handler(sound.itsStream.run).run))
                _inside.handlerThreads.append(threading.Thread(target=thread_handler(sound.handleRun).run))
            
            printDebug(6)
            for thread in _inside.streamThreads:
                thread.start()
                
            time.sleep((globals.chunkSize / 2.5) / 1000)
            
            printDebug(7)
            for thread in _inside.handlerThreads:
                thread.start()
        
        printDebug(30)
        for sound in self.syncEvents:
            printDebug(sound)
            threading.Thread(target=sound.initStream).start()
        
        printDebug(4)
        for sound in self.syncEvents:
            time.sleep(0.05) # Preserved sync sleep
            # Explicit spin-lock loop (Preserved)
            while not sound.doneLoading:
                time.sleep(0.1)
                print("Waiting...")
        
        startTime = time.perf_counter()
        self.hasRan = []
        
        # Fast inline sorting lambda
        self.syncEvents.sort(key=lambda x: x.startDelay, reverse=True)
        
        printDebug(31)
        self._isWaiting = True
        self.nextDelay = 0
        self.currentDelay = 0
        
        while self._isWaiting and not globals.close:
            self._isWaiting = False
            self.currentSyncEvents = []
            self.streamThreads = []
            self.handlerThreads = []
            
            delay_diff = self.nextDelay - self.currentDelay
            if delay_diff < 0.1:
                intenseSleep(delay_diff)
            else:
                st = time.perf_counter()
                time.sleep(delay_diff - 0.1)
                intenseSleep(0.1 - (time.perf_counter() - (st + (delay_diff - 0.1))))
            
            # Cache perf_counter to avoid re-polling system time in loop
            perf_now = time.perf_counter() 
            for sound in self.syncEvents:
                if (sound.startDelay + startTime) < perf_now:
                    if sound.uuid not in self.hasRan:
                        self.hasRan.append(sound.uuid)
                        self.currentSyncEvents.append(sound)
                        self.currentDelay = sound.startDelay
                else:
                    self.nextDelay = sound.startDelay
                    self._isWaiting = True
            
            if self.currentSyncEvents:
                threading.Thread(target=begin, args=(self.currentSyncEvents,)).start()


# Main execution
if __name__ == "__main__":
    for arg in sys.argv:
        log.crash(os.getpid())
        if arg.startswith("--event="):
            # Using split limit ensures trailing "=" in base64 padding aren't accidentally split
            event_b64 = arg.split("=", 1)[1]
            print(event_b64)
            
            eventData = json.loads(pytools.cipher.base64_decode(event_b64))
            multiEvent(eventData).run()