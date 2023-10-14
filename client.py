import modules.audio as audio
import modules.pytools as pytools
import modules.defferedTools as tools
import modules.logManager as log

import vm

from http import HTTPStatus

from http.server import BaseHTTPRequestHandler, HTTPServer
import urllib.parse
import json

import sys
import time
import traceback
import subprocess
import os
import threading
import random
import math

import wmi
import psutil

print = log.printLog

class util:
    def getHallowIndex(timeStamp, noDay=False):
        u = math.floor(timeStamp / (365 * 24 * 60 * 60))
        w = (timeStamp - (24 * 60 * 60) - (u * (365 * 24 * 60 * 60)) - 1)
        q = math.floor(math.floor(((u) / (4))) - (((u) / (4))) + 1) * 24 * 60 * 60
        a = 100
        b = 26265600 + q
        c = 3000000000000
        f = 30931200 + q
        g = 300000000000
        p = 3.14159265359
        h = 50
        e = 2.71828182846
        j = 16 * math.sin((((p) / (1180295.8))) * ( - (w - (((1180295.8) / (2)))) - (u * (365.25 * 24 * 60 * 60))))
        l_2 = 13 * e ** ( - (((w - 1080000) ** (2)) / (g)))
        l_3 = 13 * e ** ( - (((w - 3758400) ** (2)) / (g)))
        l_4 = 13 * e ** ( - ((((w - q) - 6177600) ** (2)) / (g)))
        l_5 = 13 * e ** ( - ((((w - q) - 8856000) ** (2)) / (g)))
        l_6 = 13 * e ** ( - ((((w - q) - 11448000) ** (2)) / (g)))
        l_7 = 13 * e ** ( - ((((w - q) - 14126400) ** (2)) / (g)))
        l_8 = 13 * e ** ( - ((((w - q) - 16718400) ** (2)) / (g)))
        l_9 = 13 * e ** ( - ((((w - q) - 19396800) ** (2)) / (g)))
        l_10 = 13 * e ** ( - ((((w - q) - 22075200) ** (2)) / (g)))
        l_11 = 13 * e ** ( - ((((w - q) - 24667200) ** (2)) / (g)))
        l_12 = 13 * e ** ( - ((((w - q) - 27345600) ** (2)) / (g)))
        l_13 = 13 * e ** ( - ((((w - q) - 29937600) ** (2)) / (g)))
        r = 29376000 + q
        s = 27302400 + q
        t = - 2 * ((a * e ** ( - (((w - r) ** (2)) / (c)))) + (h * e ** ( - (((w - r) ** (2)) / (g)))))
        z = - 2 * ((a * e ** ( - (((((w - s) ** (2)) / (c))) / (0.15)))) + (h * e ** ( - (((((w - s) ** (2)) / (g))) / (0.15)))))
        k = 18 * math.sin((((p) / (302400.0))) * ((w + 36 * 60 * 60) + (u * 365.25 * 24 * 60 * 60) - 6))
        z_1 = 16 * math.sin((((p) / (1180295.8))) * ( - (24778000.0 - (((1180295.8) / (2)))) - (u * (356.25 * 24 * 60 * 60)))) + (7 * math.sin((((p) / (302400.0))) * ((24778000.0 + 12 * 60 * 60) + (u * 365.25 * 24 * 60 * 60) - 6))) + 13
        o = - 3 * ((a * e ** ( - (((w - f) ** (2)) / (c)))) + (h * e ** ( - (((w - f) ** (2)) / (g)))))
        m = (1.11 * (((((math.fabs(z_1 )) / (2)) + 15) / (15)) ** (1) * (a * e ** ( - 0.65 * (((w - b) ** (2)) / (c))))) + (h * e ** ( - 0.65 * (((w - b) ** (2)) / (g))))) + j + k + (2 * (l_2 + l_3 + l_4 + l_5 + l_6 + l_7 + l_8 + l_9 + l_10 + l_11 + l_12 + l_13)) + o + t + z - 40
        n = - 10 * math.sin(((p) / (12 * 60 * 60)) * (w - 6 * 60 * 60))
        z_2 = ((1) / (2)) * (n * (((m) / (10))) + m)
        if noDay:
            return m
        else:
            return z_2

def handle_one_request(self: BaseHTTPRequestHandler):
    """Handle a single HTTP request.

    You normally don't need to override this method; see the class
    __doc__ string for information on how to handle specific HTTP
    commands such as GET and POST.

    """
    try:
        self.raw_requestline = self.rfile.readline(524289)
        if len(self.raw_requestline) > 524289:
            self.requestline = ''
            self.request_version = ''
            self.command = ''
            self.send_error(HTTPStatus.REQUEST_URI_TOO_LONG)
            return
        if not self.raw_requestline:
            self.close_connection = True
            return
        if not self.parse_request():
            # An error code has been sent, just exit
            return
        mname = 'do_' + self.command
        if not hasattr(self, mname):
            self.send_error(
                HTTPStatus.NOT_IMPLEMENTED,
                "Unsupported method (%r)" % self.command)
            return
        method = getattr(self, mname)
        method()
        self.wfile.flush() #actually send the response if not already done.
    except TimeoutError as e:
        #a read or a write timed out.  Discard this connection
        self.log_error("Request timed out: %r", e)
        self.close_connection = True
        return

BaseHTTPRequestHandler.handle_one_request = handle_one_request

class flags:
    skipCompile = False
    restart = False
    
class threads:
    threadHttp = False
    threadVoicemeeter = False
    threadVConfigure = False
    threadSleepHandler = False
    soundHandler = False
    
class system:
    
    sleepState = -1
    sleepStateCount = 0
    
    def sleepHandler():
        while True:
            try:
                loadResponse = pytools.net.getJsonAPI("http://" + vm.server.hostname + ":5597?json=" + urllib.parse.quote(json.dumps({
                    "command": "getLoad"
                })))
                load = loadResponse["data"]
                loadPercent = (load[1] / load[0]) * 100
                print("Load Percent: " + str(loadPercent))
                print("Current end of chain status: " + str(vm.configure.vban.getDaisyChain()[0] == False))
                print("Current hallowed stay on status: " + str(False == ((util.getHallowIndex(pytools.clock.dateArrayToUTC(pytools.clock.getDateTime()), noDay=True) < 45) and (util.getHallowIndex(pytools.clock.dateArrayToUTC(pytools.clock.getDateTime()), noDay=True) > -240))))
                print("Current sleep state count: " + str(system.sleepStateCount))
                if (util.getHallowIndex(pytools.clock.dateArrayToUTC(pytools.clock.getDateTime()), noDay=True) < 45) and (util.getHallowIndex(pytools.clock.dateArrayToUTC(pytools.clock.getDateTime()), noDay=True) > -240):
                    if loadPercent < 40:
                        if system.sleepStateCount > 60:
                            if vm.configure.vban.getDaisyChain()[0] == False:
                                system.sleepStateCount = 0
                                pytools.IO.saveList(".\\sleepActive.derp", "")
                                system.sleepState = True
                        system.sleepStateCount = system.sleepStateCount + 1
                    else:
                        system.sleepStateCount = 0
                else:
                    system.sleepStateCount = 0
                if system.sleepState != -1:
                    if loadPercent > 75:
                        os.system("del \".\\sleepActive.derp\" /f /q")
                        system.sleepState = False
                        pytools.net.getJsonAPI("http://" + vm.server.hostname + ":5597?json=" + urllib.parse.quote(json.dumps({
                            "command": "removeBlackList"
                        })))
                        os.system("del \".\\wokeUp.derp\" /f /q")
                    if system.sleepState:
                        pytools.net.getJsonAPI("http://" + vm.server.hostname + ":5597?json=" + urllib.parse.quote(json.dumps({
                            "command": "setBlackList"
                        })))
                        if puppet.getSoundCount() <= 1:
                            system.sleepStateCount = 60
                            pytools.IO.saveFile("wokeUp.derp", "")
                            os.system("rundll32.exe powrprof.dll, SetSuspendState Sleep")
                else:
                    try:
                        os.system("del \".\\sleepActive.derp\" /f /q")
                        system.sleepState = False
                        success = pytools.net.getJsonAPI("http://" + vm.server.hostname + ":5597?json=" + urllib.parse.quote(json.dumps({
                            "command": "removeBlackList"
                        })))["status"] == "success"
                        os.system("del \".\\wokeUp.derp\" /f /q")
                        if success:
                            system.sleepState = False
                    except:
                        print(traceback.format_exc())
            except:
                print(traceback.format_exc())
            time.sleep(10 * random.random() + 1)

class soundRegister:
    buffer = []
    maxSoundCount = -1
    soundCount = 0
    
    def run():
        while True:
            try:
                if soundRegister.maxSoundCount == -1:
                    puppet.killEvents()
                    puppet.getMaxSoundCount()
            except:
                print(traceback.format_exc())
            try:
                soundRegister.soundCount = puppet.getSoundCount()
                i = 0
                while i < len(soundRegister.buffer):
                    soundRegister.soundCount = puppet.getSoundCount()
                    if soundRegister.soundCount < (soundRegister.maxSoundCount * 0.6):
                        puppet.fireEvent(*soundRegister.buffer[i], fromBuffer=True)
                        soundRegister.buffer.pop(i)
                        i = i - 1
                    else:
                        try:
                            print("Attempting to transfer audio event...")
                            response = pytools.net.getJsonAPI("http://" + vm.server.hostname + ":" + str(random.randint(6000, 6029)) + "?json=" + urllib.parse.quote(json.dumps({
                                "command": "transferEvent",
                                "data": soundRegister.buffer[i][0],
                                "fileData": soundRegister.buffer[i][1]
                            })))
                            if response["status"]:
                                print("Audio event transfered.")
                                soundRegister.buffer.pop(i)
                                i = i - 1
                        except:
                            print(traceback.format_exc())
                    i = i + 1
            except:
                print(traceback.format_exc())
            time.sleep(0.1)

class puppet:
    def getBenchmark():
        print("Getting benchmark...")
        return tools.benchmark.get()
    
    def getMaxSoundCount():
        print("Running benchmark test...")
        if soundRegister.maxSoundCount == -1:
            soundRegister.maxSoundCount = tools.benchmark.getNumberOfPlugins(tools.benchmark.get())
        return soundRegister.maxSoundCount
    
    def getSoundCount():
        print("Getting sound count...")
        return len(subprocess.getoutput("tasklist /fi \"IMAGENAME eq ambience.exe\" /fo:csv").split("\n"))
    
    def restart():
        print("Restarting client...")
        os.system("taskkill /f /im ambience.exe")
        flags.restart = True
        vm.flags.restart = True
        
    def sleep():
        print("Entering sleep state...")
        os.system("rundll32.exe powrprof.dll, SetSuspendState Sleep")
    
    def fireEvent(eventBytes, fileData, fromBuffer=False):
        if puppet.getSoundCount() < (soundRegister.maxSoundCount * 0.6):
            print("Audio events received.")
            if not flags.restart:
                if fileData:
                    try:
                        pytools.IO.saveBytes(".\\sound\\assets\\" + fileData["fileName"].split(";")[0], pytools.cipher.base64_decode(fileData["data"], isBytes=True))
                    except:
                        print(traceback.format_exc())
                eventData = json.loads(pytools.cipher.base64_decode(eventBytes))
                i = 0
                while i < len(eventData["events"]):
                    eventData["events"][i]["path"] = eventData["events"][i]["path"].replace("\\working\\", "\\")
                    print("Firing Audio Event " + str(eventData["events"][i]["path"]) + "...")
                    i = i + 1
                eventData["wait"] = False
                if eventData["wait"]:
                    os.system("start /d \"" + os.getcwd().replace("\\working", "") + "\" /b /wait "" .\\ambience.exe .\\modules\\audio.py --event=\"" + pytools.cipher.base64_encode(json.dumps(eventData)) + "\"")
                else:
                    os.system("start /d \"" + os.getcwd().replace("\\working", "") + "\" /b "" .\\ambience.exe .\\modules\\audio.py --event=\"" + pytools.cipher.base64_encode(json.dumps(eventData)) + "\"")
        elif not fromBuffer:
            puppet.registerEvent(eventBytes, fileData)

    def registerEvent(eventBytes, fileData):
        soundRegister.buffer.append([eventBytes, fileData])

    def generateFlag(flagName, bool):
        print("Setting flag " + str(flagName) + " to " + str(bool) + "...")
        if bool:
            pytools.IO.saveFile(flagName + ".derp", "")
        else:
            os.system("del \"" + flagName + ".derp\" /f /q")

    def killEvents():
        print("Killing system...")
        os.system("taskkill /f /im WerFault.exe")
        os.system("taskkill /f /im ambience.exe")
        
    def suspendEvents():
        print("Suspending events...")
        f = wmi.WMI()
        for process in f.Win32_Process():
            if process.name == "ambience.exe":
                p = psutil.Process(process.ProcessId)
                p.suspend()
                
    def isVoicemeeterWorking():
        try:
            if "StreamClock" == vm.globals.instance.get("vban.outstream[0].name", string=True):
                return True
            else:
                return False
        except:
            print(traceback.format_exc())
            return False
            
        
    def unsuspendEvents():
        print("Unsuspending events...")
        f = wmi.WMI()
        for process in f.Win32_Process():
            if process.name == "ambience.exe":
                p = psutil.Process(process.ProcessId)
                p.resume()
        
class compiler:
        def runGlobal():
            sounds = os.listdir(".\\sound\\assets")
            for sound in sounds:
                print("Compiling Sound " + sound + "...")
                try:
                    if (sound.find(".mp3") != -1) or (sound.find(".wav") != -1):
                        soundData = audio.soundEvent(".\\sound\\assets\\" + sound, 100, 1.0, "clock", False, 0)
                        soundData.load(0)
                        i = 1
                        while soundData.data:
                            soundData.load(i)
                            i = i + 1
                        print("Compiled.")
                    else:
                        print("Not audio file. Moving on...")
                except:
                    print("An error was encountered compiling sound file " + sound + ". Stack Trace: \n" + traceback.format_exc())

class com:
    # Python 3 server example

    hostName = "0.0.0.0"
    serverPort = 4507
    
    webServer = False
    
    # Structure
    # ---------
    # {
    #     "command": "<command>"
    #     "data": {}
    # }
    
    class httpCommands:
        def _Get(request):
            jsonRequest = urllib.parse.parse_qs(urllib.parse.unquote_plus(request))
            print(jsonRequest)
            return json.loads(jsonRequest["/?json"][0])
            # print("\"" + jsonRequest + "\"")
            # return json.loads(jsonRequest)

    class MyServer(BaseHTTPRequestHandler):
        def do_GET(self):
            if flags.restart == True:
                exit()
            try:
                self.send_response(200)
                self.send_header("Content-type", "application/json")
                self.end_headers()
                request = com.httpCommands._Get(self.path)
                if request["command"] == "getBenchmark":
                    self.wfile.write(bytes(json.dumps({
                        "benchmark": puppet.getBenchmark()
                    }), "utf-8"))
                if request["command"] == "getMaxSoundCount":
                    self.wfile.write(bytes(json.dumps({
                        "maxSoundCount": puppet.getMaxSoundCount()
                    }), "utf-8"))
                if request["command"] == "getVoicemeeterStatus":
                    self.wfile.write(bytes(json.dumps({
                        "status": puppet.isVoicemeeterWorking()
                    }), "utf-8"))
                if request["command"] == "getSoundCount":
                    self.wfile.write(bytes(json.dumps({
                        "soundCount": puppet.getSoundCount()
                    }), "utf-8"))
                if request["command"] == "fireEvent":
                    try:
                        puppet.fireEvent(request["data"], request["fileData"])
                    except:
                        puppet.fireEvent(request["data"], False)
                    self.wfile.write(bytes(json.dumps({
                        "status": "success"
                    }), "utf-8"))
                if request["command"] == "setFlag":
                    puppet.generateFlag(request["data"]["flagName"], request["data"]["bool"])
                    self.wfile.write(bytes(json.dumps({
                        "status": "success"
                    }), "utf-8"))
                if request["command"] == "killEvents":
                    puppet.killEvents()
                    self.wfile.write(bytes(json.dumps({
                        "status": "success"
                    }), "utf-8"))
                if request["command"] == "restart":
                    puppet.restart()
                    self.wfile.write(bytes(json.dumps({
                        "status": "success"
                    }), "utf-8"))
                    time.sleep(3)
                    com.webServer.server_close()
                    exit()
                if request["command"] == "ping":
                    self.wfile.write(bytes(json.dumps({
                        "status": "success"
                    }), "utf-8"))
            except:
                print(traceback.format_exc())
                self.send_error(400, traceback.format_exc())

    def start():
        com.webServer = HTTPServer((com.hostName, com.serverPort), com.MyServer)
        print("Server started http://%s:%s" % (com.hostName, com.serverPort))

        try:
            com.webServer.serve_forever()
        except KeyboardInterrupt:
            pass

        com.webServer.server_close()
        print("Server stopped.")

    def run():
        if not flags.skipCompile:
            compiler.runGlobal()
        threads.threadHttp = threading.Thread(target=com.start)
        threads.soundHandler = threading.Thread(target=soundRegister.run)
        threads.threadVoicemeeter = threading.Thread(target=vm.vm.handler)
        threads.threadVConfigure = threading.Thread(target=vm.configure.handler)
        threads.threadHttp.start()
        threads.soundHandler.start()
        threads.threadVoicemeeter.start()
        threads.threadVConfigure.start()
        
        if os.path.exists(".\\doAutoSleep.derp"):
            threads.threadSleepHandler = threading.Thread(target=system.sleepHandler)
            threads.threadSleepHandler.start()
        
        pytools.IO.saveJson(".\\benchmark.json", {"soundMax": tools.benchmark.getNumberOfPlugins(tools.benchmark.get())})
        while not flags.restart:
            time.sleep(1)
            try:
                while pytools.net.getJsonAPI("http://localhost:4507?json=" + urllib.parse.quote(json.dumps({
                    "command": "ping"
                })))["status"] == "success":
                    time.sleep(15)
                threadHttp = threading.Thread(target=com.start)
                threadHttp.start()
                time.sleep(1)
            except:
                threadHttp = threading.Thread(target=com.start)
                threadHttp.start()
                time.sleep(1)
        try:
            com.webServer.server_close()
        except:
            pass

try:
    for flag in sys.argv:
        if flag == "--skipCompile":
            flags.skipCompile = True 
    if sys.argv[1] == "--run":
        com.run()
except:
    pass
            