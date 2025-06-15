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
        
    def fixStatus():
        while not flags.restart:
            if not vm.isProcessResponding("voicemeeter8.exe"):
                if os.path.exists("..\Voicemeeter.lnk"):
                    if ("voicemeeter8.exe" in (p.name() for p in psutil.process_iter())) == True:
                        os.system("taskkill /f /im voicemeeter8.exe")
                    os.system('start /b "" ..\Voicemeeter.lnk')
            time.sleep(5)
    
    def checkStatus():
        try:
            globals.instance.get("option.buffer.mme")
        except:
            print("regrabbing...")
            vm.launch()
            globals.instance = voicemeeter.remote("potato")
            globals.instance.login()
            vm.changed = True
        
    def launch():
        if os.path.exists("C:\Program Files (x86)\VB\Voicemeeter\\voicemeeter8.exe"):
            if os.path.exists("..\Voicemeeter.lnk"):
                if ("voicemeeter8.exe" in (p.name() for p in psutil.process_iter())) == False:
                    os.system("taskkill /f /im voicemeeter8.exe")
                    os.system('start /b "" ..\Voicemeeter.lnk')
            else:
                if ("voicemeeter8.exe" in (p.name() for p in psutil.process_iter())) == False:
                    installDate = pytools.clock.getDateArrayFromUST(os.path.getctime("C:\Program Files (x86)\VB\Voicemeeter\\voicemeeter8.exe"))
                    os.system("start /d \"C:\Program Files (x86)\VB\Voicemeeter\" \"\" RunAsDate.exe /immediate /movetime " + str(installDate[2]) + "\\" + str(installDate[1]) + "\\" + str(installDate[0]) + " " + str(installDate[3]) + ":" + str(installDate[4]) + ":" + str(installDate[5]) + " \"C:\\Program Files (x86)\\VB\\Voicemeeter\\voicemeeter8.exe\"")
        time.sleep(5)
        
    def handler():
        while not flags.restart:
            try:
                configure.fixAudioDg()
            except:
                pass
            try:
                vm.checkStatus()
            except:
                pass
            time.sleep(1)
            

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
            # clock = False
            # fireplace = False
            # window = False
            # for device in devices:
            #     if device["name"] == "VoiceMeeter Input (VB-Audio Voi":
            #         clock = True
            #     if device["name"] == "VoiceMeeter Aux Input (VB-Audio":
            #         fireplace = True
            #     if device["name"] == "VoiceMeeter VAIO3 Input (VB-Aud":
            #         window = True
            
            # soundOutputs = False
            # if clock:
                # if fireplace:
                    # if window:
                    
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
            
            # if soundOutputs:
            #     try:
            #         extras = pytools.IO.getJson("extraOutputs.json")["list"]
            #     except:
            #         extras = []
            #     
            #     if extras != []:
            #         for extra in extras:
            #             soundOutputs[extra] = ["", "MME"]
            #             
            #     i = 4
            #     while (i < len(outFinal)) and (i < len(soundOutputs)):
            #         soundOutputs[extras[i - 4]] = [outFinal[i]["name"], "MME"]
            #         i = i + 1
                
            return soundOutputs
        
        def getInputsOld():
            devices = sd.query_devices()
            out = {}
            outFinal = []
            sortedKey = []
            for device in devices:
                if device["name"].find("VB-Audio Virt") != -1:
                    if device["hostapi"] == 0:
                        if device["max_input_channels"] > 0:
                            out[device["name"]] = device
                            sortedKey.append([device["name"], device["name"].split("(")[1]])
            sortedKey = sorted(sortedKey, key = lambda s: sum(map(ord, s[1])), reverse=False)
            i = 0
            while i < len(sortedKey):
                outFinal.append(out[sortedKey[i][0]])
                i = i + 1
            clock = False
            fireplace = False
            window = False
            for device in devices:
                if device["name"] == "VoiceMeeter Input (VB-Audio Voi":
                    clock = True
                if device["name"] == "VoiceMeeter Aux Input (VB-Audio":
                    fireplace = True
                if device["name"] == "VoiceMeeter VAIO3 Input (VB-Aud":
                    window = True
            
            soundInputs = False
            if clock:
                if fireplace:
                    if window:
                        soundInputs = {
                            "clock": ["VoiceMeeter Input (VB-Audio Voi", "MME"],
                            "fireplace": ["VoiceMeeter Aux Input (VB-Audio", "MME"],
                            "window": ["VoiceMeeter VAIO3 Input (VB-Aud", "MME"],
                            "outside": [outFinal[0]["name"], "MME"],
                            "porch": [outFinal[1]["name"], "MME"],
                            "generic": [outFinal[2]["name"], "MME"],
                            "light": [outFinal[3]["name"], "MME"]
                        }
                        
            # if soundInputs:
                # try:
                #     extras = pytools.IO.getJson("extraOutputs.json")["list"]
                # except:
                #     extras = []
                # 
                # if extras != []:
                #     for extra in extras:
                #         soundInputs[extra] = ["", "MME"]
                        
            for input in soundInputs:
                i = 0
                fin = False
                while i < 100:
                    try:
                        if soundInputs[input][0].find("(" + str(i) + "-") != -1:
                            if configure.local.getOutputs()[input][0].find("(" + str(i) + "-") == -1:
                                for sortedDevice in outFinal:
                                    if sortedDevice["name"].find("(" + str(i) + "-") != -1:
                                        soundInputs[input] = [sortedDevice["name"], "MME"]
                                        fin = True
                                        break
                    except:
                        pass
                    if fin:
                        break
                    i = i + 1
                if not fin:
                     for sortedDevice in outFinal:
                        if sortedDevice["name"].find("(VB-Audio Virtual") != -1:
                            soundInputs[input] = [sortedDevice["name"], "MME"]
                            break
            
            return soundInputs
        
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
            
            # try:
            #     extras = pytools.IO.getJson("extraOutputs.json")["list"]
            # except:
            #     extras = []
            # 
            # if extras != []:
            #     for extra in extras:
            #         soundInputs[extra] = ["", "MME"]
            
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
        
        def setOutputs(fix=False):
            outputs = configure.local.getOutputs()
            pytools.IO.saveJson(".\\soundOutputs.json", outputs)
            if outputs:
                if globals.instance.inputs[0].device != configure.local.getInputs()["outside"][0]:
                    globals.instance.set("Strip[0].device.mme", configure.local.getInputs()["outside"][0])
                if globals.instance.inputs[1].device != configure.local.getInputs()["porch"][0]:
                    globals.instance.set("Strip[1].device.mme", configure.local.getInputs()["porch"][0])
                if globals.instance.inputs[2].device != configure.local.getInputs()["generic"][0]:
                    globals.instance.set("Strip[2].device.mme", configure.local.getInputs()["generic"][0])
                if globals.instance.inputs[3].device != configure.local.getInputs()["light"][0]:
                    globals.instance.set("Strip[3].device.mme", configure.local.getInputs()["light"][0])
                if globals.instance.get("Bus[0].device.name", string=True) != sd.query_devices()[sd.default.device[1]]["name"]:
                    if sd.query_devices()[sd.default.device[1]]["hostapi"] == 0:
                        globals.instance.set("Bus[0].device.mme", sd.query_devices()[sd.default.device[1]]["name"])
                    else:
                        globals.instance.set("Bus[0].device.wdm", sd.query_devices()[sd.default.device[1]]["name"])
                        
                def doPlugnPlay():
                    for input in globals.instance.inputs:
                        input.A1 = False
                        input.A2 = False
                        input.A3 = False
                        input.A4 = False
                        input.A5 = False
                        input.B1 = False
                        input.B2 = False
                        input.B3 = False
                        input.mute = False
                    globals.instance.inputs[5].A2 = True
                    globals.instance.inputs[6].A3 = True
                    globals.instance.inputs[7].A4 = True
                    globals.instance.inputs[0].A5 = True
                    globals.instance.inputs[1].B1 = True
                    globals.instance.inputs[2].B2 = True
                    globals.instance.inputs[3].B3 = True
                if globals.instance.inputs[5].A2 != True:
                    doPlugnPlay()
                if globals.instance.inputs[6].A3 != True:
                    doPlugnPlay()
                if globals.instance.inputs[7].A4 != True:
                    doPlugnPlay()
                if globals.instance.inputs[0].A5 != True:
                    doPlugnPlay()
                if globals.instance.inputs[1].B1 != True:
                    doPlugnPlay()
                if globals.instance.inputs[2].B2 != True:
                    doPlugnPlay()
                if globals.instance.inputs[3].B3 != True:
                    doPlugnPlay()
                                            
                vm.changed = False
    
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
        
        def setValues(skip=False):
            clients = configure.vban.getDaisyChain()
            
            if flags.manualReturn:
                clients[1] = flags.manualReturn
            
            if clients[0] != False:
                if globals.instance.get("vban.instream[0].ip", string=True) != clients[0]:
                    globals.instance.set("vban.instream[0].name", "StreamClock")
                    globals.instance.set("vban.instream[0].ip", clients[0])
                    globals.instance.set("vban.instream[0].port", 6980)
                    globals.instance.set("vban.instream[0].route", 5)
                    globals.instance.set("vban.instream[0].on", 1)
                
                if globals.instance.get("vban.instream[1].ip", string=True) != clients[0]:
                    globals.instance.set("vban.instream[1].name", "StreamFireplace")
                    globals.instance.set("vban.instream[1].ip", clients[0])
                    globals.instance.set("vban.instream[1].port", 6980)
                    globals.instance.set("vban.instream[1].route", 6)
                    globals.instance.set("vban.instream[1].on", 1)
                    
                if globals.instance.get("vban.instream[2].ip", string=True) != clients[0]:
                    globals.instance.set("vban.instream[2].name", "StreamWindow")
                    globals.instance.set("vban.instream[2].ip", clients[0])
                    globals.instance.set("vban.instream[2].port", 6980)
                    globals.instance.set("vban.instream[2].route", 7)
                    globals.instance.set("vban.instream[2].on", 1)
                
                if globals.instance.get("vban.instream[3].ip", string=True) != clients[0]:
                    globals.instance.set("vban.instream[3].name", "StreamOutside")
                    globals.instance.set("vban.instream[3].ip", clients[0])
                    globals.instance.set("vban.instream[3].port", 6980)
                    globals.instance.set("vban.instream[3].route", 0)
                    globals.instance.set("vban.instream[3].on", 1)
                
                if globals.instance.get("vban.instream[4].ip", string=True) != clients[0]:
                    globals.instance.set("vban.instream[4].name", "StreamPorch")
                    globals.instance.set("vban.instream[4].ip", clients[0])
                    globals.instance.set("vban.instream[4].port", 6980)
                    globals.instance.set("vban.instream[4].route", 1)
                    globals.instance.set("vban.instream[4].on", 1)
                
                if globals.instance.get("vban.instream[5].ip", string=True) != clients[0]:
                    globals.instance.set("vban.instream[5].name", "StreamGeneric")
                    globals.instance.set("vban.instream[5].ip", clients[0])
                    globals.instance.set("vban.instream[5].port", 6980)
                    globals.instance.set("vban.instream[5].route", 2)
                    globals.instance.set("vban.instream[5].on", 1)
                
                if globals.instance.get("vban.instream[6].ip", string=True) != clients[0]:
                    globals.instance.set("vban.instream[6].name", "StreamLight")
                    globals.instance.set("vban.instream[6].ip", clients[0])
                    globals.instance.set("vban.instream[6].port", 6980)
                    globals.instance.set("vban.instream[6].route", 3)
                    globals.instance.set("vban.instream[6].on", 1)
            
            if clients[1] != False:
                if globals.instance.get("vban.outstream[0].ip", string=True) != clients[1]:
                    globals.instance.set("vban.outstream[0].name", "StreamClock")
                    globals.instance.set("vban.outstream[0].ip", clients[1])
                    globals.instance.set("vban.outstream[0].port", 6980)
                    globals.instance.set("vban.outstream[0].route", 1)
                    globals.instance.set("vban.outstream[0].channel", 8)
                    globals.instance.set("vban.outstream[0].on", 1)
                
                if globals.instance.get("vban.outstream[1].ip", string=True) != clients[1]:
                    globals.instance.set("vban.outstream[1].name", "StreamFireplace")
                    globals.instance.set("vban.outstream[1].ip", clients[1])
                    globals.instance.set("vban.outstream[1].port", 6980)
                    globals.instance.set("vban.outstream[1].route", 2)
                    globals.instance.set("vban.outstream[1].channel", 8)
                    globals.instance.set("vban.outstream[1].on", 1)
                
                if globals.instance.get("vban.outstream[2].ip", string=True) != clients[1]:
                    globals.instance.set("vban.outstream[2].name", "StreamWindow")
                    globals.instance.set("vban.outstream[2].ip", clients[1])
                    globals.instance.set("vban.outstream[2].port", 6980)
                    globals.instance.set("vban.outstream[2].route", 3)
                    globals.instance.set("vban.outstream[2].channel", 8)
                    globals.instance.set("vban.outstream[2].on", 1)
                
                if globals.instance.get("vban.outstream[3].ip", string=True) != clients[1]:
                    globals.instance.set("vban.outstream[3].name", "StreamOutside")
                    globals.instance.set("vban.outstream[3].ip", clients[1])
                    globals.instance.set("vban.outstream[3].port", 6980)
                    globals.instance.set("vban.outstream[3].route", 4)
                    globals.instance.set("vban.outstream[3].on", 1)
                
                if globals.instance.get("vban.outstream[4].ip", string=True) != clients[1]:
                    globals.instance.set("vban.outstream[4].name", "StreamPorch")
                    globals.instance.set("vban.outstream[4].ip", clients[1])
                    globals.instance.set("vban.outstream[4].port", 6980)
                    globals.instance.set("vban.outstream[4].route", 5)
                    globals.instance.set("vban.outstream[4].on", 1)
                
                if globals.instance.get("vban.outstream[5].ip", string=True) != clients[1]:
                    globals.instance.set("vban.outstream[5].name", "StreamGeneric")
                    globals.instance.set("vban.outstream[5].ip", clients[1])
                    globals.instance.set("vban.outstream[5].port", 6980)
                    globals.instance.set("vban.outstream[5].route", 6)
                    globals.instance.set("vban.outstream[5].on", 1)
                
                if globals.instance.get("vban.outstream[6].ip", string=True) != clients[1]:
                    globals.instance.set("vban.outstream[6].name", "StreamLight")
                    globals.instance.set("vban.outstream[6].ip", clients[1])
                    globals.instance.set("vban.outstream[6].port", 6980)
                    globals.instance.set("vban.outstream[6].route", 7)
                    globals.instance.set("vban.outstream[6].on", 1)
                
            if globals.instance.get("vban.Enable") != 1:
                globals.instance.set("vban.Enable", 1)
                
            configure.vban.clientsOld = clients
            
    def handler():
        # sb = sandboxie.Sandboxie()
        # sb.start("py.exe multiVm.py --run --id=0", box="foo", wait=False)

        try:
            while configure.vban.clientsOld != configure.vban.getDaisyChain():
                try:
                    configure.local.setOutputs()
                    configure.vban.setValues(skip=True)
                except:
                    print(traceback.format_exc())
                time.sleep(1)
            configure.vban.clientsOld = []
            vm.changed = True
        except:
            pass
        counter = 0
        while not flags.restart:
            try:
                os.system("taskkill /f /im WerFault.exe")
                if vm.changed:
                    configure.local.setOutputs()
                configure.vban.setValues()
                audio.tools.setOutputs()
                if counter > 4:
                    os.system("del speakerSets.json /f /q")
                    counter = 0
                counter = counter + 1
                time.sleep(1 + (2 * random.random()))
            except:
                print(traceback.format_exc())
                time.sleep(1)

class vbanStream:
    def __init__(self, speakerType):
        self.speakerType = speakerType
        self.previousReceive = False
        self.previousSend = False
        
    def killProcess(self):
        os.system("taskkill /f /im vbanStream_" + self.speakerType + ".exe")
    
    def startProcess(self, clients):
        os.system("copy \"" + sys.executable + "\" \""  + "\\".join(sys.executable.split("\\")[:-1]) + "\\vbanStream_" + self.speakerType + ".exe\" /y")
        os.system("copy \"C:\\Windows\\py.exe\" \".\\vbanStream_" + self.speakerType + ".exe\" /y")
        os.system("start /min \"\" \".\\vbanStream_" + self.speakerType + ".exe\" vban_stream.py --run --clients=" + str(clients[0]) + "," + str(clients[1]) + " --speakerType=" + self.speakerType + " --hostname=" + server.hostname) 
        
    def updateClients(self, clients):
        
        if clients[1] != self.previousSend:
            self.killProcess()
            self.startProcess(clients)
            self.previousReceive = clients[0]
            self.previousSend = clients[1]
        
        if (clients[0] != self.previousReceive) and (self.previousReceive == False):
            self.killProcess()
            self.startProcess(clients)
            self.previousReceive = clients[0]
            self.previousSend = clients[1]

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
        
        while (not flags.restart) and (not exitf) and not (streams.exitf):
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
            time.sleep(1)
        
        streamClock.killProcess()
        streamFireplace.killProcess()
        streamWindow.killProcess()
        streamOutside.killProcess()
        streamPorch.killProcess()
        streamGeneric.killProcess()
        streamLight.killProcess()
        
        streams.isRunning = False
        streams.hasExited = True
            

    def handlerOld():
        streams.exitf = False
        streams.isRunning = True
        
        try:
            outputs = configure.local.getOutputs()
            outputsOld = outputs
            pytools.IO.saveJson(".\\soundOutputs.json", outputs)
            
            audio.tools.setOutputs()

            clients = configure.vban.getDaisyChain()
            clientsOld = clients

            if flags.manualReturn:
                clients[1] = flags.manualReturn

            streamClock = vban.speaker("clock", clients[0], clients[1])
            streamFireplace = vban.speaker("fireplace", clients[0], clients[1])
            streamWindow = vban.speaker("window", clients[0], clients[1])
            streamOutside = vban.speaker("outside", clients[0], clients[1])
            streamPorch = vban.speaker("porch", clients[0], clients[1])
            streamGeneric = vban.speaker("generic", clients[0], clients[1])
            streamLight = vban.speaker("light", clients[0], clients[1])

            streamClock.serverHostname = server.hostname
            streamFireplace.serverHostname = server.hostname
            streamWindow.serverHostname = server.hostname
            streamOutside.serverHostname = server.hostname
            streamPorch.serverHostname = server.hostname
            streamGeneric.serverHostname = server.hostname
            streamLight.serverHostname = server.hostname
            
            
            streamClock.run()
            streamFireplace.run()
            streamWindow.run()
            streamOutside.run()
            streamPorch.run()
            streamGeneric.run()
            streamLight.run()

            exitf = False

            lastUpdatedOld = streams.lastUpdated
        except:
            print(traceback.format_exc())

        while (not flags.restart) and (not exitf) and not (streams.exitf):
            streams.isRunning = True
            try:
                types = {}
                for thread in vban.pyvban.utils.sender.allf.senderUUIDs:
                    try:
                        types[vban.pyvban.utils.sender.allf.senderUUIDs[thread][1]._stream_name] 
                    except:
                        types[vban.pyvban.utils.sender.allf.senderUUIDs[thread][1]._stream_name] = []
                    types[vban.pyvban.utils.sender.allf.senderUUIDs[thread][1]._stream_name].append([thread, vban.pyvban.utils.sender.allf.senderUUIDs[thread]])
                
                for speaker in types:
                    loopCount = 0

                    inf = 0
                    toRemove = {}
                    for thread in types[speaker]:
                        if thread[1][1]._hasStopped:
                            vban.pyvban.utils.sender.allf.senderUUIDs.pop(thread[1][1]._uuid)
                            if not speaker in toRemove:
                                toRemove[speaker] = []
                            toRemove[speaker].append(inf)

                for speaker in toRemove:
                    for intf in toRemove[speaker]:
                        try:
                            types[speaker].pop(intf)
                        except:
                            print(traceback.format_exc())
                    
                    
                for speaker in types:
                    while (len(types[speaker]) > 1) and (loopCount < 100):
                        randomInt = random.randint(0, len(types[speaker]) - 1)
                        randomStream = types[speaker][randomInt][1]
                        loopCount = 0
                        while (not randomStream[1]._hasStopped) and (loopCount < 100):
                            try:
                                print("Stopping thread with uuid of " + str(types[speaker][randomInt][0]))
                                randomStream[1].stop()
                            except:
                                pass
                            loopCount = loopCount + 1
                            time.sleep(0.1)
                        
                        if loopCount < 100:
                            types[speaker].pop(randomInt)
                            vban.pyvban.utils.sender.allf.senderUUIDs.pop(randomStream[1]._uuid)

                outJson = {}
                for speaker in types:
                    for thread in types[speaker]:
                        if not speaker in outJson:
                            outJson[speaker] = []
                        outJson[speaker].append([thread[0], thread[1][0], thread[1][2]])
                
                pytools.IO.saveJson("streamThreads.json", {
                    "speakers": outJson,
                    "error": False
                })
            except:
                exc = traceback.format_exc()
                print(exc)
                
                try:
                    outJson = {}
                    for speaker in types:
                        for thread in types[speaker]:
                            if not speaker in outJson:
                                outJson[speaker] = []
                            outJson[speaker].append([thread[0], thread[1][0], thread[1][2]])
                except:
                    outJson = {}
                    
                pytools.IO.saveJson("streamThreads.json", {
                    "speakers": {},
                    "error": exc
                })

            try:
                clients = configure.vban.getDaisyChain()

                streamClock.serverHostname = server.hostname
                streamFireplace.serverHostname = server.hostname
                streamWindow.serverHostname = server.hostname
                streamOutside.serverHostname = server.hostname
                streamPorch.serverHostname = server.hostname
                streamGeneric.serverHostname = server.hostname
                streamLight.serverHostname = server.hostname

                outputs = configure.local.getOutputs()
                pytools.IO.saveJson(".\\soundOutputs.json", outputs)

                if flags.manualReturn:
                    clients[1] = flags.manualReturn
            
                if (clientsOld != clients) or (outputsOld != outputs):

                    print("Updated clients detected...")
                
                    audio.tools.setOutputs()

                    # streamClock.setReceiveFromIp(clients[0])
                    streamClock.setSendToIp(clients[1])
                    
                    # streamFireplace.setReceiveFromIp(clients[0])
                    streamFireplace.setSendToIp(clients[1])

                    # streamWindow.setReceiveFromIp(clients[0])
                    streamWindow.setSendToIp(clients[1])
                    
                    # streamOutside.setReceiveFromIp(clients[0])
                    streamOutside.setSendToIp(clients[1])
                    
                    # streamPorch.setReceiveFromIp(clients[0])
                    streamPorch.setSendToIp(clients[1])
                    
                    # streamGeneric.setReceiveFromIp(clients[0])
                    streamGeneric.setSendToIp(clients[1])
                    
                    # streamLight.setReceiveFromIp(clients[0])
                    streamLight.setSendToIp(clients[1])

                    clientsOld = clients
                    outputsOld = outputs
            except:
                print(traceback.format_exc())

            try:
                def _streamWatchDog(streamf: vban.speaker, clients):
                    try:
                        if ((streamf.lastUpdated + 60) < time.time()):
                            print("Stream watchdog detected crashed stream of type " + str(streamf.speakerType) + ". Restarting...")
                            streamf.exitf = True

                            try:
                                while not streamf.isRunning:
                                    streamf.exitf = True
                                    print("    > Waiting for stream of type " + str(streamf.speakerType) + " to exit...")
                                    time.sleep(0.1)
                            except:
                                pass
                            
                            try:
                                while not streamf.transmitterThread.vbanObj.lastActivityTimestamp:
                                    streamf.exitf = True
                                    print("    > Waiting for stream of type " + str(streamf.speakerType) + " to exit...")
                                    time.sleep(0.1)
                            except:
                                pass
                            
                            

                            streamNew = vban.speaker(streamf.speakerType, clients[0], clients[1])
                            streamNew.run()
                            return streamNew
                    except:
                        print(traceback.format_exc())
                    return streamf

                streamClock = _streamWatchDog(streamClock, clients)
                streamFireplace = _streamWatchDog(streamFireplace, clients)
                streamWindow = _streamWatchDog(streamWindow, clients)
                streamOutside = _streamWatchDog(streamOutside, clients)
                streamPorch = _streamWatchDog(streamPorch, clients)
                streamGeneric = _streamWatchDog(streamGeneric, clients)
                streamLight = _streamWatchDog(streamLight, clients)

            except:
                print(traceback.format_exc())

            try:
                if streams.lastUpdated != lastUpdatedOld:
                    exitf = True
                
                streams.lastUpdated = time.time()
                lastUpdatedOld = copy.deepcopy(streams.lastUpdated)
            except:
                print(traceback.format_exc())

            time.sleep(1)
            print("Handler looping...")

        print("Handler has exited.")
        streamClock.exitf = True
        streamFireplace.exitf = True
        streamWindow.exitf = True
        streamOutside.exitf = True
        streamPorch.exitf = True
        streamGeneric.exitf = True
        streamLight.exitf = True
        
        streams.isRunning = False
        streams.hasExited = True
        

                    


                    

            
            
            