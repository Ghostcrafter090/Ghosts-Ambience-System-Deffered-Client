import time
import math

def printDebug(strf):
    if True:
        print(strf)

# Sound Events
# syncEvents = {
#     "events": [
#         {
#             "path": "",
#             "volume": 0,
#             "speed": 1.0,
#             "channel": "clock",
#             "effects": [
#                  {
#                      "type": "<type>", # lowpass, highpass, remeberbypass
#                      <highpass, lowpass> "freqency": <float>
#                      <highpass, lowpass> "db": <float>
#                 }
#             ]
#         },
#     ],
#     "wait": <bool>
# }

class obj:
    activeSounds = {}

testEvent = {
    "events": [
        {
            "path": ".\\sound\\assets\\dnwbella.mp3",
            "volume": 10,
            "speed": 1.3,
            "channel": "fireplace",
            "effects": [
                 {
                     "type": "lowpass",
                     "freqency": 1000,
                     "db": 20
                }
            ]
        },
        {
            "path": ".\\sound\\assets\\dnwbella.mp3",
            "volume": 10,
            "speed": 1.3,
            "channel": "clock",
            "effects": [
                 {
                     "type": "lowpass",
                     "freqency": 1000,
                     "db": 20
                }
            ]
        },
        {
            "path": ".\\sound\\assets\\dnwbella.mp3",
            "volume": 10,
            "speed": 1.3,
            "channel": "window",
            "effects": [
                 {
                     "type": "lowpass",
                     "freqency": 1000,
                     "db": 20
                }
            ]
        },
    ],
    "wait": True
}

class globals:
    bufferSize = 8
    chunkSize = 8192
    speakers = {}
    maxCount = 100
    close = False

class pytools:
    class clock:
        def getDateTime(utc = False):
            from datetime import datetime
            if utc:
                daten = datetime.utcnow()
            else:
                daten = datetime.now()
            dateArray = [1970, 1, 1, 0, 0, 0]
            dateArray[0] = int(str(daten).split(" ")[0].split("-")[0])
            dateArray[1] = int(str(daten).split(" ")[0].split("-")[1])
            dateArray[2] = int(str(daten).split(" ")[0].split("-")[2])
            dateArray[3] = int(str(daten).split(" ")[1].split(":")[0])
            dateArray[4] = int(str(daten).split(" ")[1].split(":")[1])
            dateArray[5] = int(str(daten).split(" ")[1].split(":")[2].split(".")[0])
            return dateArray
    
    class cipher:  
        def base64_encode(s):
            import base64
            encode = base64.standard_b64encode(bytes(s, encoding="utf-8")).decode("utf-8").replace("=", "?")
            return encode
            
        def base64_decode(s: str):
            import base64
            decode = base64.standard_b64decode(s.replace("?", "=")).decode("utf-8")
            return decode
    
    class IO:
        def getJson(path, doPrint=True):
            import json
            import sys
            error = 0
            try:
                file = open(path, "r")
                jsonData = json.loads(file.read())
                file.close()
            except:
                if doPrint:
                    print("Unexpected error:", sys.exc_info())
                error = 1
            if error != 0:
                jsonData = error
            return jsonData
        
        def getXml(path, doPrint=True):
            import xmltodict
            return xmltodict.parse(pytools.IO.getFile(path, doPrint=doPrint))
        
        def saveXml(path, doPrint=True):
            pass

        def saveJson(path, jsonData):
            import json
            import sys
            error = 0
            try:
                file = open(path, "w")
                file.write(json.dumps(jsonData))
                file.close()
            except:
                print("Unexpected error:", sys.exc_info())
                error = 1
            return error

        def getFile(path, doPrint=True):
            import sys
            error = 0
            try:
                file = open(path, "r")
                jsonData = file.read()
                file.close()
            except:
                if doPrint:
                    print("Unexpected error:", sys.exc_info())
                error = 1
            if error != 0:
                jsonData = error
            return jsonData
        
        def getBytes(path, doPrint=True):
            import sys
            error = 0
            try:
                file = open(path, "rb")
                jsonData = file.read()
                file.close()
            except:
                if doPrint:
                    print("Unexpected error:", sys.exc_info())
                error = 1
            if error != 0:
                jsonData = error
            return jsonData

        def saveFile(path, jsonData):
            import sys
            error = 0
            try:
                file = open(path, "w")
                file.write(jsonData)
                file.close()
            except:
                print("Unexpected error:", sys.exc_info())
                error = 1
            return error
        
        def saveBytes(path, jsonData):
            import sys
            error = 0
            try:
                file = open(path, "wb")
                file.write(jsonData)
                file.close()
            except:
                print("Unexpected error:", sys.exc_info())
                error = 1
            return error

        def saveList(path, list):
            import pickle
            import sys
            error = 0
            try:
                file = open(path, "wb")
                pickle.dump(list, file)
                file.close()
            except:
                print("Unexpected error:", sys.exc_info())
                error = 1
            return error

        def getList(path, doPrint=True):
            import pickle
            import sys
            list = []
            error = 0
            try:
                file = open(path, "rb")
                jsonData = pickle.load(file)
                file.close()
            except:
                if doPrint:
                    print("Unexpected error:", sys.exc_info())
                error = 1
            if error != 0:
                jsonData = error
            return [list, jsonData]

        def appendFile(path, jsonData):
            import sys
            error = 0
            try:
                file = open(path, "a")
                file.write(jsonData)
                file.close()
            except:
                print("Unexpected error:", sys.exc_info())
                error = 1
            return error
        
        def unpack(path, outDir):
            import zipfile
            try:
                with zipfile.ZipFile(path, 'r') as zip_ref:
                    print(zip_ref.printdir())
                    print('Extracting zip resources...')
                    zip_ref.extractall(outDir)
                    print("Done.")
            except Exception as erro:
                    print("Could not unpack zip file.")
                    print(erro)

        def pack(path, dir):
            import shutil
            shutil.make_archive(path, 'zip', dir)

import os
if os.path.exists(".\\soundOutputs.json"):
    globals.speakers = pytools.IO.getJson(".\\soundOutputs.json")
if os.path.exists("..\\soundOutputs.json"):
    globals.speakers = pytools.IO.getJson("..\\soundOutputs.json")
    
class tools:
    def setOutputs():
        if os.path.exists(".\\soundOutputs.json"):
            globals.speakers = pytools.IO.getJson(".\\soundOutputs.json")
        if os.path.exists("..\\soundOutputs.json"):
            globals.speakers = pytools.IO.getJson("..\\soundOutputs.json")
        try:
            import sounddevice as sd
            devices = sd.query_devices()
            for channel in globals.speakers:
                for n in devices:
                    import time
                    time.sleep(0.1)
                    if globals.speakers[channel][0] == n["name"]:
                        if globals.speakers[channel][1] == "MME":
                            if n["hostapi"] == 0:
                                deviceIndex = n["index"]
                                break
                        if globals.speakers[channel][1] == "WDM-KS":
                            if n["hostapi"] == 4:
                                deviceIndex = n["index"]
                                break
                globals.speakers[channel].append(deviceIndex)
            pytools.IO.saveJson("speakerSets.json", {
                "speakers": globals.speakers
            })
        except:
            import traceback
            print(traceback.format_exc())
    
class audioEffects:
    def lowPass(data, frequency, db=24):
        from pydub.scipy_effects import low_pass_filter
        return data.low_pass_filter(frequency, order=db)
    
    def highPass(data, frequency, db=24):
        from pydub.scipy_effects import high_pass_filter
        return data.high_pass_filter(frequency, order=db)
        
class stream:
    def __init__(self, seg, speed, device, duration, soundIndex, lastPlayed, startPlayed, bufferSize, balence):
        import pydub.utils
        self.channels = seg.channels
        self.frame_rate = seg.frame_rate
        self.sample_width = seg.sample_width
        self.chunksActive = pydub.utils.make_chunks(seg, globals.chunkSize)
        self.chunks = False
        self.speed = speed
        self.device = device
        self.duration = duration
        self.soundIndex = soundIndex
        self.lastPlayed = lastPlayed
        self.startPlayed = startPlayed
        self.bufferSize = bufferSize
        
    audioStream = False
    p = False
    
    def run(self):
        printDebug(self.channels)
        
        printDebug(self.chunksActive)

        try:
            import time
            import math
            print((self.startPlayed + (self.duration * 1000000) + (5 * 1000000)))
            print(round(time.time() * 1000000))
            loopTic = 0
            while (self.startPlayed + (self.duration * 1000000) + (5 * 1000000)) > round(time.time() * 1000000):
                self.chunks = self.chunksActive
                self.chunksActive = True
                if (self.chunks != True) and (self.chunks != False):
                    def forChunkMapFunction(chunk):
                        self.audioStream.write(chunk._data)
                    list(map(forChunkMapFunction, self.chunks))
                else:
                    time.sleep(0.1)
                        
            self.audioStream.stop_stream()
            self.audioStream.close()

            self.p.terminate()
            globals.close = True
            exit()
            
        except:
            import traceback
            printDebug(traceback.format_exc())
            self.audioStream.stop_stream()
            self.audioStream.close()

            self.p.terminate()
            globals.close = True
            exit()

class soundEvent:
    def __init__(self, path, volume, speed, channel, effects, balence):
        self.path = path
        import random
        self.uuid = random.random()
        while self.uuid in obj.activeSounds:
            self.uuid = random.random()
        self.volume = volume
        self.speed = speed
        self.balence = balence
        self.channel = channel
        self.effects = effects
        if path.find(".mp3") != -1:
            from mutagen.mp3 import MP3
            self.duration = float(MP3(path).info.length) / speed
        else:
            from mutagen.wave import WAVE
            self.duration = float(WAVE(path).info.length) / speed
            
    def initStream(self):
        try:
            try:
                try:
                    globals.speakers = pytools.IO.getJson("speakerSets.json")["speakers"]
                except:
                    pass
                printDebug(self.channel)
                deviceIndex = globals.speakers[self.channel][2]
                import sounddevice as sd
                if globals.speakers[self.channel][0] != sd.query_devices()[deviceIndex]["name"]:
                    import sounddevice as sd
                    devices = sd.query_devices()
                    for n in devices:
                        import time
                        time.sleep(0.1)
                        if globals.speakers[self.channel][0] == n["name"]:
                            if globals.speakers[self.channel][1] == "MME":
                                if n["hostapi"] == 0:
                                    deviceIndex = n["index"]
                                    break
                            if globals.speakers[self.channel][1] == "WDM-KS":
                                if n["hostapi"] == 4:
                                    deviceIndex = n["index"]
                                    break
                    globals.speakers[self.channel].append(deviceIndex)
                    pytools.IO.saveJson("speakerSets.json", {
                        "speakers": globals.speakers
                    })
            except:
                import sounddevice as sd
                devices = sd.query_devices()
                for n in devices:
                    import time
                    time.sleep(0.1)
                    if globals.speakers[self.channel][0] == n["name"]:
                        if globals.speakers[self.channel][1] == "MME":
                            if n["hostapi"] == 0:
                                deviceIndex = n["index"]
                                break
                        if globals.speakers[self.channel][1] == "WDM-KS":
                            if n["hostapi"] == 4:
                                deviceIndex = n["index"]
                                break
                globals.speakers[self.channel].append(deviceIndex)
                pytools.IO.saveJson("speakerSets.json", {
                    "speakers": globals.speakers
                })
            from pyaudio import PyAudio
            import time
            self.itsStream = stream(self.data, self.speed, deviceIndex, self.duration, self.index, self.lastPlayed, round(time.time() * 1000000), globals.bufferSize, self.balence)
            self.itsStream.p = PyAudio()
            self.itsStream.audioStream = self.itsStream.p.open(
                format=self.itsStream.p.get_format_from_width(self.itsStream.sample_width),
                channels=self.itsStream.channels,
                output_device_index=self.itsStream.device,
                rate=int(self.itsStream.frame_rate * self.speed),
                output=True
            )
        except:
            import traceback
            printDebug(traceback.format_exc())
        
    data = False
    itsStream = False
    index = 0
    lastPlayed = 0
    
    def load(self, index):
        self.index = index
        import math
        if math.floor((self.duration / globals.bufferSize) + 1) >= index:
            import os
            lastModif = os.path.getmtime(self.path)
            if os.path.exists(".\\.audiocache\\" + self.path.split("\\")[-1] + "-cache." + str(index * globals.bufferSize) + ".pyl"):
                printDebug("".join(["loading cached index " + str(index), "..."]))
                cachedData = pytools.IO.getList(".\\.audiocache\\" + self.path.split("\\")[-1] + "-cache." + str(index * globals.bufferSize) + ".pyl")[1]
                self.data = cachedData[0]
                if cachedData[1] != lastModif:
                    printDebug("".join(["not cached! loading index " + str(index), "..."]))
                    import pydub
                    self.data = pydub.AudioSegment.from_file(file=self.path.replace("\t", "\\t"), format="mp3", start_second=index * globals.bufferSize, duration=globals.bufferSize)
                    pytools.IO.saveList(".\\.audiocache\\" + self.path.split("\\")[-1] + "-cache." + str(index * globals.bufferSize) + ".pyl", [self.data, lastModif])
            else:
                printDebug("".join(["not cached! loading index " + str(index), "..."]))
                import pydub
                self.data = pydub.AudioSegment.from_file(file=self.path.replace("\t", "\\t"), format="mp3", start_second=index * globals.bufferSize, duration=globals.bufferSize)
                pytools.IO.saveList(".\\.audiocache\\" + self.path.split("\\")[-1] + "-cache." + str(index * globals.bufferSize) + ".pyl", [self.data, lastModif])
        else:
            self.data = False
        if self.balence != 0:
            monoSets = self.data.split_to_mono()
            bal = False
            if len(monoSets) == 1:
                import pydub
                monoSets = [monoSets[0], monoSets[0]]
                self.data = pydub.AudioSegment.from_mono_audiosegments(*monoSets)
            if self.balence < 0:
                monoSets[1] = monoSets[1] + (20 * math.log((0.01 + 100 - math.fabs(self.balence)) / 100, 10))
                bal = True
            elif self.balence > 0:
                monoSets[0] = monoSets[0] + (20 * math.log((0.01 + 100 - math.fabs(self.balence)) / 100, 10))
                bal = True
            if bal:
                import pydub
                self.data = pydub.AudioSegment.from_mono_audiosegments(*monoSets)
    
    def iter(self):
        self.load(self.index + 1)
        
    def handleEffects(self, effect):
        if effect["type"] == "lowpass":
            try:
                self.data = audioEffects.lowPass(self.data, effect["frequency"], effect["db"])
            except:
                self.data = audioEffects.lowPass(self.data, effect["frequency"])
                
        if effect["type"] == "highpass":
            try:
                self.data = audioEffects.highPass(self.data, effect["frequency"], effect["db"])
            except:
                self.data = audioEffects.highPass(self.data, effect["frequency"])
    
    def handleRun(self):
        try:
            import time
            import math
            startPlayed = round(time.time() * 1000000)
            obj.activeSounds[self.uuid] = self.path.split("\\")[-1]
            print("".join(["Playing sound of path ", self.path, " on the ", self.channel, " channel at volume ", str((20 * math.log(self.volume / 100, 10))), " at ", str(self.speed), "x speed..."]))
            while self.data != False:
                time.sleep(0.05)
                if globals.close:
                    exit()
                self.iter()
                import math
                shift = (20 * math.log(self.volume / 100, 10))
                self.data = self.data + shift
                # for effect in self.effects:
                def handleEffectsMapFunction(effect):
                    if globals.close:
                        exit()
                    self.handleEffects(effect)
                list(map(handleEffectsMapFunction, self.effects))
                import pydub
                self.itsStream.chunksActive = pydub.utils.make_chunks(self.data, globals.chunkSize)
                self.lastPlayed = (startPlayed + (self.index * 1000000)) / 1000000
                self.itsStream.lastPlayed = self.lastPlayed
                while self.itsStream.chunksActive != True:
                    if globals.close:
                        exit()
                    time.sleep(0.5)
            obj.activeSounds.pop(self.uuid)
        except:
            import traceback
            printDebug(traceback.format_exc())
        exit()
        
class multiEvent:
    def __init__(self, eventData):
        self.wait = eventData["wait"]
        self.eventData = eventData
        def loadEventsMapFunction(event):
            import time
            time.sleep(0.1)
            if event["volume"] > 0.0:
                if os.path.exists(".\\randomSounds.derp"):
                    audioList = os.listdir(".\\sound\\assets")
                    import random
                    event["path"] = "".join([".\\sound\\assets\\", audioList[random.randint(0, len(audioList))]]).replace("\\", "\\")
                    while (event["path"].find(".mp3") == -1) and (event["path"].find(".wav") == -1):
                        time.sleep(0.1)
                        event["path"] = "".join([".\\sound\\assets\\", audioList[random.randint(0, len(audioList))]]).replace("\\", "\\")
                if os.path.exists(".\\speakSounds.derp"):
                    if not os.path.exists("".join([".\\sound\\assets\\speak_troll-", event["path"].split("\\")[-1], ".wav"]).replace("\\", "\\")):
                        ln = 1
                        try:
                            if event["path"].find(".mp3") == -1:
                                from mutagen.wave import WAVE
                                audiowave = WAVE("".join([".\\sound\\assets\\", event["path"].split("\\")[-1]]).replace("\\", "\\"))
                                ln = int(audiowave.info.length) + 1
                            else:
                                from mutagen.mp3 import MP3
                                audiomp3 = MP3("".join([".\\sound\\assets\\", event["path"].split("\\")[-1]]).replace("\\", "\\"))
                                ln = int(audiomp3.info.length) + 1
                        except:
                            pass
                        textf = "".join([event["path"].split("\\")[-1].replace("_", " ").replace(".mp3", "").replace(".wav", ""), " "]).replace("\\", "\\")
                        textf = textf * (int(ln / (len(textf.split(" ")))) + 1)
                        import gtts
                        gtts.gTTS(text=textf, lang="en", slow=False).save("".join([".\\sound\\assets\\speak_troll-" + event["path"].split("\\")[-1], ".wav"]).replace("\\", "\\"))
                    event["path"] = "".join([".\\sound\\assets\\", "speak_troll-", event["path"].split("\\")[-1], ".wav"]).replace("\\", "\\")
                self.syncEvents.append(soundEvent(event["path"].replace("\\working\\", "\\"), event["volume"], event["speed"], event["channel"], event["effects"], event["balence"]))
        list(map(loadEventsMapFunction, eventData["events"]))
    
    def load(self):
        def loadSoundsMapFunction(sound):
            import time
            time.sleep(0.05)
            sound.load(0)
        list(map(loadSoundsMapFunction, self.syncEvents))
            
    def iter(self, event=False, index=False):
        if event:
            if index:
                self.syncEvents[event].load(index)
            else:
                self.syncEvents[event].iter()
        else:
            if index:
                # for sound in self.syncEvents:
                def soundLoadMapFunction(sound):
                    import time
                    time.sleep(0.05)
                    sound.load(index)
                list(map(soundLoadMapFunction, self.syncEvents))
            else:
                # for sound in self.syncEvents:
                def soundIterMapFunction(sound):
                    import time
                    time.sleep(0.05)
                    sound.iter()
                list(map(soundIterMapFunction, self.syncEvents))
                
    def process(self, event=False):
        if event:
            import math
            shift = (20 * math.log(self.syncEvents[event].volume / 100, 10))
            self.syncEvents[event].data = self.syncEvents[event].data + shift
            def processEffectMapFunction(effect):
                import time
                time.sleep(0.05)
                self.syncEvents[event].handleEffects(effect)
            list(map(processEffectMapFunction, self.syncEvents[event].effects))
        else:
            def processSoundMapFunction(sound):
                import math
                shift = (20 * math.log(sound.volume / 100, 10))
                sound.data = sound.data + shift
                import time
                time.sleep(0.05)
                list(map(sound.handleEffects, sound.effects))
            list(map(processSoundMapFunction, self.syncEvents))
                    
    def run(self):
        print("running...")
        printDebug(0)
        self.load()
        printDebug(1)
        self.process()
        printDebug(2)
        
        printDebug(3)
        # for sound in self.syncEvents:
        def initStreamMapFunction(sound):
            import time
            time.sleep(0.05)
            printDebug(sound)
            sound.initStream()
        list(map(initStreamMapFunction, self.syncEvents))
        
        printDebug(4)
        # for sound in self.syncEvents:
        def streamWaitMapFunction(sound):
            import time
            time.sleep(0.05)
            # printDebug("waiting on: " + str(i))
            while sound.itsStream == False:
                time.sleep(0.1)
        list(map(streamWaitMapFunction, self.syncEvents))
            
        printDebug(5)
        # for sound in self.syncEvents:
        def streamThreadAppendMapFunction(sound):
            import time
            time.sleep(0.05)
            printDebug(sound)
            import threading
            self.streamThreads.append(threading.Thread(target=sound.itsStream.run))
            self.handlerThreads.append(threading.Thread(target=sound.handleRun))
        list(map(streamThreadAppendMapFunction, self.syncEvents))
            
        printDebug(6)
        # for thread in self.streamThreads:
        def threadStartMapFunction(thread):
            import time
            time.sleep(0.05)
            printDebug(thread)
            thread.start()
        list(map(threadStartMapFunction, self.streamThreads))
        
        printDebug(7)
        # for thread in self.handlerThreads:
        def handlerThreadStartMapFunction(thread):
            import time
            time.sleep(0.05)
            # printDebug("launching: " + str(i))
            thread.start()
        list(map(handlerThreadStartMapFunction, self.handlerThreads))
        
        # if self.wait == 1:
        #     # for thread in self.handlerThreads:
        #     def handlerThreadJoinMapFunction(thread):
        #         time.sleep(0.1)
        #         thread.join()
        #     list(map(handlerThreadJoinMapFunction, self.handlerThreads))
            
    syncEvents = []
    
    streamThreads = []
    handlerThreads = []
    
class playSoundWindow:
    def __init__(self, path, volume, speed, balence, wait, remember=False, lowPass=False, highPass=False, play=True):
        self.path = path
        self.volume = volume
        self.speed = speed
        self.balence = balence
        self.wait = wait
        self.remember = remember
        self.lowPass = lowPass
        self.highPass = highPass
        self.run(play=play)
        
    eventData = {}
    
    def getVolume(self, intf):
        if str(self.volume)[0] == "[":
            return self.volume[intf]
        else:
            return self.volume
    
    def run(self, play=True):
        effects = []
        if self.lowPass:
            effects.append({
                "type": "lowpass",
                "frequency": self.lowPass,
                "db": 24
            })
        if self.highPass:
            effects.append({
                "type": "highpass",
                "frequency": self.highPass,
                "db": 24
            })
        if self.remember:
            effects.append({
                "type": "rememberbypass",
            })
        
        if self.path.split(";")[0] != self.path:
            if os.path.exists(".\\nomufflewn.derp"):
                eventData = {
                    "events": [
                        {
                            "path": ".\\sound\\assets\\" + self.path.split(";")[1],
                            "volume": self.getVolume(1),
                            "speed": self.speed,
                            "balence": self.balence,
                            "channel": "windown",
                            "effects": effects
                        },
                    ],
                    "wait": self.wait
                }
                import random
                uuid = random.random()
                while uuid in obj.activeSounds:
                    uuid = random.random()
                if self.path.split(";")[1].find(".mp3") != -1:
                    from mutagen.mp3 import MP3
                    duration = float(MP3(".\\sound\\assets\\" + self.path.split(";")[1]).info.length) / self.speed
                else:
                    from mutagen.wave import WAVE
                    duration = float(WAVE(".\\sound\\assets\\" + self.path.split(";")[1]).info.length) / self.speed
                obj.activeSounds[uuid] = [self.path.split(";")[1].split("\\")[-1], "windown", pytools.clock.getDateTime(), duration]
            else:
                eventData = {
                    "events": [
                        {
                            "path": ".\\sound\\assets\\" + self.path.split(";")[0],
                            "volume": self.getVolume(0),
                            "speed": self.speed,
                            "balence": self.balence,
                            "channel": "window",
                            "effects": effects
                        },
                        {
                            "path": ".\\sound\\assets\\" + self.path.split(";")[1],
                            "volume": self.getVolume(1),
                            "speed": self.speed,
                            "balence": self.balence,
                            "channel": "outside",
                            "effects": effects
                        }
                    ],
                    "wait": self.wait
                }
                import random
                uuid = random.random()
                while uuid in obj.activeSounds:
                    uuid = random.random()
                if self.path.split(";")[1].find(".mp3") != -1:
                    duration = float(MP3(".\\sound\\assets\\" + self.path.split(";")[1]).info.length) / self.speed
                else:
                    duration = float(WAVE(".\\sound\\assets\\" + self.path.split(";")[1]).info.length) / self.speed
                obj.activeSounds[uuid] = [self.path.split(";")[1].split("\\")[-1], "outside", pytools.clock.getDateTime(), duration]
                uuid = random.random()
                while uuid in obj.activeSounds:
                    uuid = random.random()
                if self.path.split(";")[0].find(".mp3") != -1:
                    duration = float(MP3(".\\sound\\assets\\" + self.path.split(";")[0]).info.length) / self.speed
                else:
                    duration = float(WAVE(".\\sound\\assets\\" + self.path.split(";")[0]).info.length) / self.speed
                obj.activeSounds[uuid] = [self.path.split(";")[0].split("\\")[-1], "window", pytools.clock.getDateTime(), duration]
        else:
            if os.path.exists(".\\nomufflewn.derp"):
                eventData = {
                    "events": [
                        {
                            "path": ".\\sound\\assets\\" + self.path,
                            "volume": self.getVolume(1),
                            "speed": self.speed,
                            "balence": self.balence,
                            "channel": "windown",
                            "effects": effects
                        },
                    ],
                    "wait": self.wait
                }
                uuid = random.random()
                while uuid in obj.activeSounds:
                    uuid = random.random()
                if self.path.find(".mp3") != -1:
                    duration = float(MP3(".\\sound\\assets\\" + self.path).info.length) / self.speed
                else:
                    duration = float(WAVE(".\\sound\\assets\\" + self.path).info.length) / self.speed
                obj.activeSounds[uuid] = [self.path.split("\\")[-1], "windown", pytools.clock.getDateTime(), duration]
            else:
                eventData = {
                    "events": [
                        {
                            "path": ".\\sound\\assets\\" + self.path,
                            "volume": self.getVolume(0),
                            "speed": self.speed,
                            "balence": self.balence,
                            "channel": "window",
                            "effects": effects
                        },
                        {
                            "path": ".\\sound\\assets\\" + self.path,
                            "volume": self.getVolume(1),
                            "speed": self.speed,
                            "balence": self.balence,
                            "channel": "outside",
                            "effects": effects
                        }
                    ],
                    "wait": self.wait
                }
                uuid = random.random()
                while uuid in obj.activeSounds:
                    uuid = random.random()
                if self.path.find(".mp3") != -1:
                    duration = float(MP3(".\\sound\\assets\\" + self.path).info.length) / self.speed
                else:
                    duration = float(WAVE(".\\sound\\assets\\" + self.path).info.length) / self.speed
                obj.activeSounds[uuid] = [self.path.split("\\")[-1], "outside", pytools.clock.getDateTime(), duration]
                uuid = random.random()
                while uuid in obj.activeSounds:
                    uuid = random.random()
                if self.path.find(".mp3") != -1:
                    duration = float(MP3(".\\sound\\assets\\" + self.path).info.length) / self.speed
                else:
                    duration = float(WAVE(".\\sound\\assets\\" + self.path).info.length) / self.speed
                obj.activeSounds[uuid] = [self.path.split("\\")[-1], "window", pytools.clock.getDateTime(), duration]
        self.eventData = eventData
        if play:
            if duration < 30:
                try:
                    try:
                        test = int(pytools.IO.getFile("soundCount.cx"))
                    except:
                        test = globals.maxCount + 1
                    if test > globals.maxCount:
                        while test > globals.maxCount:
                            try:
                                test = int(pytools.IO.getFile("soundCount.cx"))
                            except:
                                test = globals.maxCount + 1
                            import time
                            time.sleep(1)
                except:
                    pass
            import json
            if self.wait:
                os.system("start /realtime /d \"" + os.getcwd().replace("\\working", "") + "\" /b /wait "" .\\ambience.exe .\\modules\\audio.py --event=\"" + pytools.cipher.base64_encode(json.dumps(eventData)) + "\"")
            else:
                os.system("start /realtime /d \"" + os.getcwd().replace("\\working", "") + "\" /b "" .\\ambience.exe .\\modules\\audio.py --event=\"" + pytools.cipher.base64_encode(json.dumps(eventData)) + "\"")
            
    
class playSoundAll:
    def __init__(self, path, volume, speed, balence, wait, remember=False, lowPass=False, highPass=False):
        self.path = path
        self.volume = volume
        self.speed = speed
        self.balence = balence
        self.wait = wait
        self.remember = remember
        self.lowPass = lowPass
        self.highPass = highPass
        self.run()
    
    def run(self):
        effects = []
        if self.lowPass:
            effects.append({
                "type": "lowpass",
                "frequency": self.lowPass,
                "db": 24
            })
        if self.highPass:
            effects.append({
                "type": "highpass",
                "frequency": self.highPass,
                "db": 24
            })
        if self.remember:
            effects.append({
                "type": "rememberbypass",
            })
        
        eventData = {
            "events": [
                {
                    "path": ".\\sound\\assets\\" + self.path,
                    "volume": self.volume,
                    "speed": self.speed,
                    "balence": self.balence,
                    "channel": "clock",
                    "effects": effects
                },
                {
                    "path": ".\\sound\\assets\\" + self.path,
                    "volume": self.volume,
                    "speed": self.speed,
                    "balence": self.balence,
                    "channel": "generic",
                    "effects": effects
                },
                {
                    "path": ".\\sound\\assets\\" + self.path,
                    "volume": self.volume,
                    "speed": self.speed,
                    "balence": self.balence,
                    "channel": "fireplace",
                    "effects": effects
                },
                {
                    "path": ".\\sound\\assets\\" + self.path,
                    "volume": self.volume,
                    "speed": self.speed,
                    "balence": self.balence,
                    "channel": "windown",
                    "effects": effects
                },
            ],
            "wait": self.wait
        }
        import random
        from mutagen.mp3 import MP3
        from mutagen.wave import WAVE
        uuid = random.random()
        while uuid in obj.activeSounds:
            uuid = random.random()
        if self.path.find(".mp3") != -1:
            duration = float(MP3(".\\sound\\assets\\" + self.path).info.length) / self.speed
        else:
            duration = float(WAVE(".\\sound\\assets\\" + self.path).info.length) / self.speed
        obj.activeSounds[uuid] = [self.path.split("\\")[-1], "clock", pytools.clock.getDateTime(), duration]
        uuid = random.random()
        while uuid in obj.activeSounds:
            uuid = random.random()
        if self.path.find(".mp3") != -1:
            duration = float(MP3(".\\sound\\assets\\" + self.path).info.length) / self.speed
        else:
            duration = float(WAVE(".\\sound\\assets\\" + self.path).info.length) / self.speed
        obj.activeSounds[uuid] = [self.path.split("\\")[-1], "generic", pytools.clock.getDateTime(), duration]
        uuid = random.random()
        while uuid in obj.activeSounds:
            uuid = random.random()
        if self.path.find(".mp3") != -1:
            duration = float(MP3(".\\sound\\assets\\" + self.path).info.length) / self.speed
        else:
            duration = float(WAVE(".\\sound\\assets\\" + self.path).info.length) / self.speed
        obj.activeSounds[uuid] = [self.path.split("\\")[-1], "fireplace", pytools.clock.getDateTime(), duration]
        uuid = random.random()
        while uuid in obj.activeSounds:
            uuid = random.random()
        if self.path.find(".mp3") != -1:
            duration = float(MP3(".\\sound\\assets\\" + self.path).info.length) / self.speed
        else:
            duration = float(WAVE(".\\sound\\assets\\" + self.path).info.length) / self.speed
        obj.activeSounds[uuid] = [self.path.split("\\")[-1], "windown", pytools.clock.getDateTime(), duration]
        if duration < 30:
            try:
                try:
                    test = int(pytools.IO.getFile("soundCount.cx"))
                except:
                    test = globals.maxCount + 1
                if test > globals.maxCount:
                    while test > globals.maxCount:
                        try:
                            test = int(pytools.IO.getFile("soundCount.cx"))
                        except:
                            test = globals.maxCount + 1
                        import time
                        time.sleep(1)
            except:
                pass
        import json
        if self.wait:
            os.system("start /realtime /d \"" + os.getcwd().replace("\\working", "") + "\" /b /wait "" .\\ambience.exe .\\modules\\audio.py --event=\"" + pytools.cipher.base64_encode(json.dumps(eventData)) + "\"")
        else:
            os.system("start /realtime /d \"" + os.getcwd().replace("\\working", "") + "\" /b "" .\\ambience.exe .\\modules\\audio.py --event=\"" + pytools.cipher.base64_encode(json.dumps(eventData)) + "\"")
            
class event:
    def __init__(self):
        self.eventData = {
            "events": [],
            "wait": False
        }
    
    eventData = {
        "events": [],
        "wait": False
    }
    
    duration = 0
    
    def registerWindow(self, path, volume, speed, balence, wait, remember=False, lowPass=False, highPass=False):
        self.eventData["events"].extend(playSoundWindow(path, volume, speed, balence, wait, remember=remember, lowPass=lowPass, highPass=highPass, play=False).eventData["events"])
    
    def register(self, path, speaker, volume, speed, balence, wait, clock=True, remember=False, lowPass=False, highPass=False, keepLoaded=False):
        
        printDebug(path + ", " + str(volume))
        
        if wait:
            self.eventData["wait"] = True
            
        effects = []
        if lowPass:
            effects.append({
                "type": "lowpass",
                "frequency": lowPass,
                "db": 24
            })
        if highPass:
            effects.append({
                "type": "highpass",
                "frequency": highPass,
                "db": 24
            })
        if remember:
            effects.append({
                "type": "rememberbypass",
            })
        
        if speaker == 0:
            if clock:
                speakern = ["clock", "generic"]
            else:
                speakern = ["clock"]
        elif speaker == 1:
            speakern = ["fireplace"]
        elif speaker == 2:
            speakern = ["window"]
        elif speaker == 3:
            speakern = ["outside"]
        elif speaker == 5:
            speakern = ["light"]
        elif speaker == 7:
            speakern = ["generic"]
        else:
            speakern = ["windown"]
        
        for channel in speakern:
            self.eventData["events"].append({
                "path": ".\\sound\\assets\\" + path,
                "volume": volume,
                "speed": speed,
                "channel": channel,
                "balence": balence,
                "effects": effects
            })
            import random
            from mutagen.mp3 import MP3
            from mutagen.wave import WAVE
            uuid = random.random()
            while uuid in obj.activeSounds:
                uuid = random.random()
            if path.find(".mp3") != -1:
                duration = float(MP3(".\\sound\\assets\\" + path).info.length) / speed
            else:
                duration = float(WAVE(".\\sound\\assets\\" + path).info.length) / speed
            try:
                if self.duration < duration:
                    self.duration = duration
            except:
                self.duration = duration
            obj.activeSounds[uuid] = [path.split("\\")[-1], channel, pytools.clock.getDateTime(), duration]
    
    def run(self, spawnChild=True):
        if self.duration < 30:
            try:
                try:
                    test = int(pytools.IO.getFile("soundCount.cx"))
                except:
                    test = globals.maxCount + 1
                if test > globals.maxCount:
                    while test > globals.maxCount:
                        try:
                            test = int(pytools.IO.getFile("soundCount.cx"))
                        except:
                            test = globals.maxCount + 1
                        import time
                        time.sleep(1)
            except:
                pass
        if spawnChild:
            import json
            if self.eventData["wait"]:
                os.system("start /realtime /d \"" + os.getcwd().replace("\\working", "") + "\" /b /wait "" .\\ambience.exe .\\modules\\audio.py --event=\"" + pytools.cipher.base64_encode(json.dumps(self.eventData)) + "\"")
            else:
                os.system("start /realtime /d \"" + os.getcwd().replace("\\working", "") + "\" /b "" .\\ambience.exe .\\modules\\audio.py --event=\"" + pytools.cipher.base64_encode(json.dumps(self.eventData)) + "\"")
        else:
            multiEvent(self.eventData).run()

import sys
for arg in sys.argv:
    import os
    print(os.getpid())
    if arg.split("=")[0] == "--event":
        import json
        eventData = json.loads(pytools.cipher.base64_decode(arg.split("=")[1]))
        multiEvent(eventData).run()
        
