import modules.audio as audio
import modules.pytools as pytools
import modules.defferedTools as tools
import vm

from http.server import BaseHTTPRequestHandler, HTTPServer
import urllib.parse
import json

import sys
import time
import traceback
import subprocess
import os
import threading

class flags:
    skipCompile = False
    restart = False
    
class threads:
    threadHttp = False
    threadVoicemeeter = False
    threadVConfigure = False

class puppet:
    def getBenchmark():
        return tools.benchmark.get()
    
    def getMaxSoundCount():
        return tools.benchmark.getNumberOfPlugins(tools.benchmark.get())
    
    def getSoundCount():
        return len(subprocess.getoutput("tasklist /fi \"IMAGENAME eq ambience.exe\" /fo:csv").split("\n"))
    
    def restart():
        os.system("taskkill /f /im ambience.exe")
        flags.restart = True
        vm.flags.restart = True
    
    def fireEvent(eventBytes, fileData):
        if not flags.restart:
            if fileData:
                try:
                    pytools.IO.saveBytes(".\\sound\\assets\\" + fileData["name"], pytools.cipher.base64_decode(fileData["data"], isBytes=True))
                except:
                    pass
            eventData = json.loads(pytools.cipher.base64_decode(eventBytes))
            i = 0
            while i < len(eventData["events"]):
                eventData["events"][i]["path"] = eventData["events"][i]["path"].replace("\\working\\", "\\")
                i = i + 1
            eventData["wait"] = False
            if eventData["wait"]:
                os.system("start /low /d \"" + os.getcwd().replace("\\working", "") + "\" /b /wait "" .\\ambience.exe .\\modules\\audio.py --event=\"" + pytools.cipher.base64_encode(json.dumps(eventData)) + "\"")
            else:
                os.system("start /low /d \"" + os.getcwd().replace("\\working", "") + "\" /b "" .\\ambience.exe .\\modules\\audio.py --event=\"" + pytools.cipher.base64_encode(json.dumps(eventData)) + "\"")

    def generateFlag(flagName, bool):
        if bool:
            pytools.IO.saveFile(flagName + ".derp", "")
        else:
            os.system("del \"" + flagName + ".derp\" /f /q")

    def killEvents():
        os.system("taskkill /f /im WerFault.exe")
        os.system("taskkill /f /im ambience.exe")
        
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
                    puppet.generateFlag(request["data"]["flagName"], request["data"]["flagName"]["bool"])
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
        threads.threadVoicemeeter = threading.Thread(target=vm.vm.handler)
        threads.threadVConfigure = threading.Thread(target=vm.configure.handler)
        threads.threadHttp.start()
        threads.threadVoicemeeter.start()
        threads.threadVConfigure.start()
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
            