import traceback
try:
    import voicemeeter
except:
    print(traceback.format_exc())
import sounddevice as sd
import time
import os
import psutil
import modules.pytools as pytools
import modules.vban as vban
import subprocess
import urllib.parse
import json
import modules.audio as audio
import random
import modules.logManager as log
import faulthandler
import copy
import sys
import threading

log.settings.debug = True

print = log.printLog

class globals:
    instance = False
    mme = 2048
    wdm = 1024
    noChange = True
    started = False
    
class flags:
    restart = False
    manualReturn = False

class server:
    
    hostname = "0.0.0.0"
    interface = "0.0.0.0"
    
    class con:
        def arp():
            ipsDirty = subprocess.getoutput("arp -a -v").split("\n")
            try:
                interfaceBlacklist = pytools.IO.getJson("excludeInterfaces.json")["list"]
            except:
                interfaceBlacklist = []
            ips = {}
            for entry in ipsDirty:
                if entry.find("Interface:") != -1:
                    interface = entry.split("Interface: ")[1].split(" ")[0]
                    if not interface in interfaceBlacklist:
                        ips[interface] = []
                elif entry.find("Internet Address") != -1:
                    pass
                else:
                    try:
                        entryf = entry.split(" ")
                        while '' in entryf:
                            entryf.remove('')
                        if not interface in interfaceBlacklist:
                            ips[interface].append(entryf[0])
                    except:
                        pass
            return ips
        
        def connect():
            oldSettings = pytools.IO.getJson("serverSettings.json")
            if os.path.exists("forceServerSettings.derp"):
                try:
                    pytools.net.getJsonAPI("http://" + oldSettings["ip"] + ":5597?json=" + urllib.parse.quote(json.dumps({
                                "command": "ping",
                                "data": {
                                    "ipAddress": oldSettings["interface"]
                                }
                            })), timeout=5)
                except:
                    print(traceback.format_exc())
                return [oldSettings["ip"], oldSettings["interface"]]
            
            try:
                os.system("ping " + oldSettings["ip"] + " -n 1")
            except:
                print("Old settings file corrupted.")
            try:
                print("Attempting to connect to last known ip address " + oldSettings["ip"] + "...")
                # pytools.net.getJsonAPI("http://" + oldSettings["interface"] + ":4507?json=" + urllib.parse.quote(json.dumps({
                #    "command": "ping"
                # })), timeout=1)
                tryCount = 0
                connected = False
                while (tryCount < 3) and (not connected):
                    try:
                        if not os.path.exists("wokeUp.derp"):
                            pytools.net.getJsonAPI("http://" + oldSettings["ip"] + ":5597?json=" + urllib.parse.quote(json.dumps({
                                "command": "ping",
                                "data": {
                                    "ipAddress": oldSettings["interface"]
                                }
                            })), timeout=5)
                        connected = True
                    except:
                        print(traceback.format_exc())
                    tryCount = tryCount + 1

                if (not os.path.exists("wokeUp.derp")) and (not connected):
                    pytools.net.getJsonAPI("http://" + oldSettings["ip"] + ":5597?json=" + urllib.parse.quote(json.dumps({
                        "command": "ping",
                        "data": {
                            "ipAddress": oldSettings["interface"]
                        }
                    })), timeout=5)

                outIp = [oldSettings["ip"], oldSettings["interface"]]
            except:
                print(traceback.format_exc())
                finished = False
                errorCount = 0
                while (not finished) or (errorCount < 2):
                    arp = server.con.arp()
                    for interface in server.con.arp():
                        try:
                            print("Attempting to connect to ip address " + ip + "...")
                            pytools.net.getJsonAPI("http://" + interface + ":5597?json=" + urllib.parse.quote(json.dumps({
                                "command": "ping",
                                "data": {
                                    "ipAddress": interface
                                }
                            })), timeout=1)
                            outIp = [interface, interface]
                            finished = True
                            break
                        except:
                            print("Failed to connect.")
                        for ip in arp[interface]:
                            try:
                                print("Attempting to connect to ip address " + ip + "...")
                                pytools.net.getJsonAPI("http://" + ip + ":5597?json=" + urllib.parse.quote(json.dumps({
                                    "command": "ping",
                                    "data": {
                                        "ipAddress": interface
                                    }
                                })), timeout=3)
                                outIp = [ip, interface]
                                finished = True
                                break
                            except:
                                print("Failed to connect.")
                    errorCount = errorCount + 1
                pytools.IO.saveJson("serverSettings.json", {
                    "ip": outIp[0],
                    "interface": outIp[1]
                })

                if errorCount >= 2:
                    return -1

            if outIp[0] == outIp[1]:
                if not os.path.exists(".\\testEnv.derp"):
                    return False
            return outIp
    
    def startConnection():
        con = server.con.connect()
        if con == -1:
            server.hostname = pytools.IO.getJson("serverSettings.json")["ip"]
            server.interface = pytools.IO.getJson("serverSettings.json")["interface"]
        else:
            server.hostname = con[0]
            server.interface = con[1]
    
    def grabOtherComputers():
        server.startConnection()
        try:
            return pytools.net.getJsonAPI("http://" + server.hostname + ":5597?json=" + urllib.parse.quote(json.dumps({
                "command": "getOtherComputers"
            })), timeout=1)
        except:
            print("Connection Failed.")
            while not flags.restart:
                server.startConnection()
                try:
                    return pytools.net.getJsonAPI("http://" + server.hostname + ":5597?json=" + urllib.parse.quote(json.dumps({
                        "command": "getOtherComputers"
                    })), timeout=1)
                except:
                    print("Connection Failed.")

class vm:
    changed = True
    
    def isProcessResponding(name):
        output = subprocess.getoutput('tasklist /FI "IMAGENAME eq ' + name + '" /FI "STATUS eq running"').split("\n")
        if name in output[-1].split()[0]:
            return True
        else:
            return False

class configure:
    def fixAudioDg():
        audioDgSize = float(subprocess.getoutput('tasklist /fi "IMAGENAME eq audiodg.exe" /fo csv').split("\n")[1].split("\",\"")[-1].replace(",", "").replace(" K\"", ""))
        if audioDgSize > 500000.0:
            print("Oversized audiodg.exe detected. Resetting...")
            os.system("taskkill /f /im audiodg.exe")
            os.system('"C:\Program Files (x86)\VB\Voicemeeter\voicemeeter8.exe" -r')
    
    class local:
        def getOutputs():
            devices = sd.query_devices()
            out = {}
            outFinal = []
            sortedKey = []
            for device in devices:
                if device["name"].find("VB-Audio Virt") != -1:
                    if device["hostapi"] == 0:
                        if device["max_output_channels"] > 0:
                            out[device["name"]] = device
                            sortedKey.append([device["name"], device["name"].split("(")[1]])
            sortedKey = sorted(sortedKey, key = lambda s: sum(map(ord, s[1])), reverse=False)
            i = 0
            while i < len(sortedKey):
                outFinal.append(out[sortedKey[i][0]])
                i = i + 1
                    
            print(outFinal)
                    
            soundOutputs = {
                "clock": [outFinal[0]["name"], "MME"], # ["VoiceMeeter Input (VB-Audio Voi", "MME"],
                "fireplace": [outFinal[1]["name"], "MME"], # ["VoiceMeeter Aux Input (VB-Audio", "MME"],
                "window": [outFinal[2]["name"], "MME"], # ["VoiceMeeter VAIO3 Input (VB-Aud", "MME"],
                "outside": [outFinal[3]["name"], "MME"],
                "porch": [outFinal[4]["name"], "MME"],
                "generic": [outFinal[5]["name"], "MME"],
                "light": [outFinal[6]["name"], "MME"]
            }
                
            return soundOutputs
        
        def getInputs():
            outputs = configure.local.getOutputs()
            soundInputs = {
                "clock": ["", "MME"], # ["VoiceMeeter Input (VB-Audio Voi", "MME"],
                "fireplace": ["", "MME"], # ["VoiceMeeter Aux Input (VB-Audio", "MME"],
                "window": ["", "MME"], # ["VoiceMeeter VAIO3 Input (VB-Aud", "MME"],
                "outside": ["", "MME"],
                "porch": ["", "MME"],
                "generic": ["", "MME"],
                "light": ["", "MME"]
            }
            
            sortedKey = []
            
            for output in outputs:
                input = outputs[output][0].replace("Speakers", "CABLE Output").replace("CABLE Input", "CABLE Output")
                while len(input) > 31:
                    input = input[:-1]
                sortedKey.append(input)
            
            soundInputs["clock"] = [sortedKey[0], "MME"]
            soundInputs["fireplace"] = [sortedKey[1], "MME"]
            soundInputs["window"] = [sortedKey[2], "MME"]
            soundInputs["outside"] = [sortedKey[3], "MME"]
            soundInputs["porch"] = [sortedKey[4], "MME"]
            soundInputs["generic"] = [sortedKey[5], "MME"]
            soundInputs["light"] = [sortedKey[6], "MME"]
            
            i = 0
            for input in soundInputs:
                if soundInputs[input][0] == "":
                    soundInputs[input][0] = sortedKey[i]
                i = i + 1
            
            for input in soundInputs:
                returnFalse = True
                print(soundInputs[input])
                for device in sd.query_devices():
                    if device["name"] == soundInputs[input][0]:
                        returnFalse = False
                if returnFalse:
                    return False
                
            return soundInputs  
    
    class vban:
        clientsOld = [False, False]
        previousDaisyChain = [False, "0.0.0.0"]
        
        isAloneCheck = 0
        
        def getDaisyChain():
            print("Grabbing clients...")
            clients = server.grabOtherComputers()["hosts"]
            if "0.0.0.0" in clients:
                clients.remove("0.0.0.0")
            if "192.168.2.40" in clients:
                clients.remove("192.168.2.40")
            permaClients = pytools.IO.getJson(".\\permaclients.json")
            if permaClients["primary"] in clients:
                try:
                    clients.remove(permaClients["primary"])
                except:
                    pass
                
                try:
                    for ignoreClient in permaClients["ignore"]:
                        if ignoreClient in clients:
                            clients.remove(ignoreClient)
                except:
                    pass
                # sortedClients = sorted(clients, key = lambda s: sum(map(ord, s[1])), reverse=False)
                sortedClients = clients
                sortedClients.append(permaClients["primary"])
            else:
                sortedClients = clients
            selfIndex = 0
            while selfIndex < len(sortedClients):
                if sortedClients[selfIndex] == server.interface:
                    break
                selfIndex = selfIndex + 1
            try:
                if selfIndex == (len(sortedClients) - 1):
                    configure.vban.isAloneCheck = configure.vban.isAloneCheck + 1
                    print("Is End Of Chain Check: " + str(configure.vban.isAloneCheck))
                    if configure.vban.isAloneCheck > 20:
                        nextClient = server.hostname
                    else:
                        return configure.vban.previousDaisyChain
                else:
                    nextClient = sortedClients[selfIndex + 1]
                    configure.vban.isAloneCheck = 0
            except:
                print(traceback.format_exc())
                print("Is End Of Chain Check: " + str(configure.vban.isAloneCheck))
                configure.vban.isAloneCheck = configure.vban.isAloneCheck + 1
                if configure.vban.isAloneCheck > 20:
                    nextClient = server.hostname
                else:
                    return configure.vban.previousDaisyChain
            if selfIndex == 0:
                previousClient = False
            else:
                previousClient = sortedClients[selfIndex - 1]
            pytools.IO.saveJson(".\\daisyChain.json", {
                "chain": [previousClient, nextClient]
            })
            configure.vban.previousDaisyChain = [previousClient, nextClient]
            return [previousClient, nextClient]

class vbanStream:
    def __init__(self, speakerType):
        self.speakerType = speakerType
        self.previousReceive = False
        self.previousSend = False
        self.lastUpdate = time.time()
        self.killProcess()
        
    def killProcess(self):
        os.system("taskkill /f /im vbanStream_" + self.speakerType + ".exe")
    
    def startProcess(self, clients=[-1, -1]):
        if clients == [-1, -1]:
            clients = [self.previousReceive, self.previousSend]
            
        os.system("copy \"" + sys.executable + "\" \""  + "\\".join(sys.executable.split("\\")[:-1]) + "\\vbanStream_" + self.speakerType + ".exe\" /y")
        os.system("copy \"C:\\Windows\\py.exe\" \".\\vbanStream_" + self.speakerType + ".exe\" /y")
        os.system("start /min \"\" \".\\vbanStream_" + self.speakerType + ".exe\" vban_stream.py --run --clients=" + str(clients[0]) + "," + str(clients[1]) + " --speakerType=" + self.speakerType + " --hostname=" + server.hostname) 
        
    def updateClients(self, clients):
        
        if clients[1] != self.previousSend:
            self.killProcess()
            self.killProcess()
            self.killProcess()
            self.killProcess()
            self.killProcess()
            self.killProcess()
            time.sleep(1)
            self.startProcess(clients)
            self.previousReceive = clients[0]
            self.previousSend = clients[1]
            self.lastUpdate = time.time()
            
        if (clients[0] != self.previousReceive): #  and ((self.previousReceive == False) or ((time.time() - self.lastUpdate) > 3600)):
            self.killProcess()
            self.killProcess()
            self.killProcess()
            self.killProcess()
            self.killProcess()
            self.killProcess()
            time.sleep(1)
            self.startProcess(clients)
            self.previousReceive = clients[0]
            self.previousSend = clients[1]
            self.lastUpdate = time.time()

class streamUtils:
    
    amountDict = {}

def getStreamProcesses(streamType):
    total = []
    
    check = subprocess.getoutput("tasklist | findstr \"vbanStream_" + str(streamType) + ".exe\"").split("\n")
    if "" in check:
        check.remove("")
    
    if len(check) in streamUtils.amountDict:
        return streamUtils.amountDict[len(check)]
    
    for process in check:
        process = process.split(" ")
        while "" in process:
            process.remove("")
            
            check2 = subprocess.getoutput('wmic process get Caption,ParentProcessId,ProcessId | findstr "' + process[1] + '"').split("\n")
            
            while "" in check2:
                check2.remove("")
            
            if len(check2) == 3:
                if not check2 in total:
                    total.append(check2)

    streamUtils.amountDict[len(check)] = len(total)
                
    return len(total)

class streams:

    lastUpdated = time.time()
    exitf = False
    hasExited = False
    isRunning = False
    
    def shutdown():
        streams.exitf = True
        while (not streams.hasExited) and streams.isRunning:
            streams.exitf = True
            time.sleep(1)
            
        streams.hasExited = False

    def _parityWatchdog(streamObj: vbanStream):
        
        check = getStreamProcesses(streamObj.speakerType)
        
        if check > 1:
            print("multiple " + streamObj.speakerType + " stream copies detected. Killing all and restarting...")
            streamObj.killProcess()
            time.sleep(random.random() * 3)
            streamObj.startProcess()
        
        elif check < 1:
            print("multiple " + streamObj.speakerType + " stream has crashed. Restarting...")
            streamObj.startProcess()

    def handler():
        clients = configure.vban.getDaisyChain()
        clientsOld = clients

        if flags.manualReturn:
            clients[1] = flags.manualReturn
        
        streamClock = vbanStream("clock")
        streamFireplace = vbanStream("fireplace")
        streamWindow = vbanStream("window")
        streamOutside = vbanStream("outside")
        streamPorch = vbanStream("porch")
        streamGeneric = vbanStream("generic")
        streamLight = vbanStream("light")
        
        streamClock.updateClients(clients)
        streamFireplace.updateClients(clients)
        streamWindow.updateClients(clients)
        streamOutside.updateClients(clients)
        streamPorch.updateClients(clients)
        streamGeneric.updateClients(clients)
        streamLight.updateClients(clients)
        
        exitf = False
        
        oldClockParityThread = threading.Thread(target=streams._parityWatchdog, args=(streamClock,))
        oldFireplaceParityThread = threading.Thread(target=streams._parityWatchdog, args=(streamFireplace,))
        oldWindowParityThread = threading.Thread(target=streams._parityWatchdog, args=(streamWindow,))
        oldOutsideParityThread = threading.Thread(target=streams._parityWatchdog, args=(streamOutside,))
        oldPorchParityThread = threading.Thread(target=streams._parityWatchdog, args=(streamPorch,))
        oldGenericParityThread = threading.Thread(target=streams._parityWatchdog, args=(streamGeneric,))
        oldLightParityThread = threading.Thread(target=streams._parityWatchdog, args=(streamLight,))
        
        oldClockParityThread.start()
        oldFireplaceParityThread.start()
        oldWindowParityThread.start()
        oldOutsideParityThread.start()
        oldPorchParityThread.start()
        oldGenericParityThread.start()
        oldLightParityThread.start()
        
        loopCounter = 0
        while (not flags.restart) and (not exitf) and not (streams.exitf):
            try:
                streams.isRunning = True
                
                clients = configure.vban.getDaisyChain()
                
                if flags.manualReturn:
                    clients[1] = flags.manualReturn
                
                streamClock.updateClients(clients)
                streamFireplace.updateClients(clients)
                streamWindow.updateClients(clients)
                streamOutside.updateClients(clients)
                streamPorch.updateClients(clients)
                streamGeneric.updateClients(clients)
                streamLight.updateClients(clients)
                
                if loopCounter > 35:
                    
                    def _attachToThread(thread: threading.Thread):
                        try:
                            thread.join()
                        except:
                            pass
                    
                    _attachToThread(oldClockParityThread)
                    _attachToThread(oldFireplaceParityThread)
                    _attachToThread(oldWindowParityThread)
                    _attachToThread(oldOutsideParityThread)
                    _attachToThread(oldPorchParityThread)
                    _attachToThread(oldGenericParityThread)
                    _attachToThread(oldLightParityThread)
                    
                    oldClockParityThread = threading.Thread(target=streams._parityWatchdog, args=(streamClock,))
                    oldFireplaceParityThread = threading.Thread(target=streams._parityWatchdog, args=(streamFireplace,))
                    oldWindowParityThread = threading.Thread(target=streams._parityWatchdog, args=(streamWindow,))
                    oldOutsideParityThread = threading.Thread(target=streams._parityWatchdog, args=(streamOutside,))
                    oldPorchParityThread = threading.Thread(target=streams._parityWatchdog, args=(streamPorch,))
                    oldGenericParityThread = threading.Thread(target=streams._parityWatchdog, args=(streamGeneric,))
                    oldLightParityThread = threading.Thread(target=streams._parityWatchdog, args=(streamLight,))
                    
                    oldClockParityThread.start()
                    oldFireplaceParityThread.start()
                    oldWindowParityThread.start()
                    oldOutsideParityThread.start()
                    oldPorchParityThread.start()
                    oldGenericParityThread.start()
                    oldLightParityThread.start()
                    
                    loopCounter = 0
                
                streams.lastUpdated = time.time()
                
                print("Streams handler is alive.")
                loopCounter = loopCounter + 1
                time.sleep(1)
            except:
                print(traceback.format_exc())
        
        streamClock.killProcess()
        streamFireplace.killProcess()
        streamWindow.killProcess()
        streamOutside.killProcess()
        streamPorch.killProcess()
        streamGeneric.killProcess()
        streamLight.killProcess()
        
        streams.isRunning = False
        streams.hasExited = True
        

                    


                    

            
            
            