import voicemeeter
import sounddevice as sd
import time
import os
import psutil
import modules.pytools as pytools
import subprocess
import urllib.parse
import json
import traceback
import modules.audio as audio
import sandboxie
import threading
import sys

class globals:
    instance = False
    mme = 2048
    id = -1
    wdm = 1024
    noChange = True
    started = False
    
class flags:
    restart = False

class vm:
    changed = True
    
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
                os.system("taskkill /f /im voicemeeter8.exe")
                os.system('start /b "" ..\Voicemeeter.lnk')
            else:
                installDate = pytools.clock.getDateArrayFromUST(os.path.getctime("C:\Program Files (x86)\VB\Voicemeeter\\voicemeeter8.exe"))
                os.system("start /d \"C:\Program Files (x86)\VB\Voicemeeter\" \"\" RunAsDate.exe /immediate /movetime " + str(installDate[2]) + "\\" + str(installDate[1]) + "\\" + str(installDate[0]) + " " + str(installDate[3]) + ":" + str(installDate[4]) + ":" + str(installDate[5]) + " \"C:\\Program Files (x86)\\VB\\Voicemeeter\\voicemeeter8.exe\"")
        time.sleep(5)
        
    def handler():
        while not flags.restart:
            try:
                vm.checkStatus()
            except:
                pass
            time.sleep(1)

class configure:
    class local:
        def getOutputs(onlyExtras=False):
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
            
            soundOutputs = False
            if clock:
                if fireplace:
                    if window:
                        soundOutputs = {
                            "clock": ["VoiceMeeter Input (VB-Audio Voi", "MME"],
                            "fireplace": ["VoiceMeeter Aux Input (VB-Audio", "MME"],
                            "window": ["VoiceMeeter VAIO3 Input (VB-Aud", "MME"],
                            "outside": [outFinal[0]["name"], "MME"],
                            "windown": [outFinal[1]["name"], "MME"],
                            "generic": [outFinal[2]["name"], "MME"],
                            "light": [outFinal[3]["name"], "MME"]
                        }
            
            if soundOutputs:
                if onlyExtras:
                    
                    soundOutputs = {}
                    
                    try:
                        extras = pytools.IO.getJson("extraOutputs.json")["list"]
                    except:
                        extras = []
                    
                    if extras != []:
                        for extra in extras:
                            soundOutputs[extra] = ["", "MME"]
                            
                    i = 4
                    while (i - 4) < len(extras):
                        soundOutputs[extras[i - 4]] = [outFinal[i]["name"], "MME"]
                        i = i + 1
                else:
                    try:
                        extras = pytools.IO.getJson("extraOutputs.json")["list"]
                    except:
                        extras = []
                    
                    if extras != []:
                        for extra in extras:
                            soundOutputs[extra] = ["", "MME"]
                    
                    i = 4
                    while i < len(soundOutputs):
                        soundOutputs[extras[i - 4]] = [outFinal[i]["name"], "MME"]
                        i = i + 1
                
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
                            "windown": [outFinal[1]["name"], "MME"],
                            "generic": [outFinal[2]["name"], "MME"],
                            "light": [outFinal[3]["name"], "MME"]
                        }
                        
            if soundInputs:
                try:
                    extras = pytools.IO.getJson("extraOutputs.json")["list"]
                except:
                    extras = []
                
                if extras != []:
                    for extra in extras:
                        soundInputs[extra] = ["", "MME"]
                        
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
        
        def getInputs(onlyExtras = False):
            outputs = configure.local.getOutputs(onlyExtras=onlyExtras)
            soundInputs = {
                "clock": ["VoiceMeeter Input (VB-Audio Voi", "MME"],
                "fireplace": ["VoiceMeeter Aux Input (VB-Audio", "MME"],
                "window": ["VoiceMeeter VAIO3 Input (VB-Aud", "MME"],
                "outside": ["", "MME"],
                "windown": ["", "MME"],
                "generic": ["", "MME"],
                "light": ["", "MME"]
            }
            
            if not onlyExtras:
                try:
                    extras = pytools.IO.getJson("extraOutputs.json")["list"]
                except:
                    extras = []
                
                if extras != []:
                    for extra in extras:
                        soundInputs[extra] = ["", "MME"]
            
            sortedKey = []
            
            for output in outputs:
                input = outputs[output][0].replace("Speakers", "CABLE Output").replace("CABLE Input", "CABLE Output")
                while len(input) > 31:
                    input = input[:-1]
                sortedKey.append(input)
            
            if not onlyExtras:
                soundInputs["outside"] = [sortedKey[3], "MME"]
                soundInputs["windown"] = [sortedKey[4], "MME"]
                soundInputs["generic"] = [sortedKey[5], "MME"]
                soundInputs["light"] = [sortedKey[6], "MME"]
            else:
                soundInputs = {}
                i = 0
                for output in outputs:
                    soundInputs[output] = [sortedKey[i], "MME"]
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
            outputs = configure.local.getOutputs(onlyExtras=True)
            
            if outputs:
                i = 0
                n = 0
                for output in outputs:
                    if (globals.id * 5) < n < ((globals.id + 1) * 5):
                        if globals.instance.inputs[i].device != configure.local.getInputs()[output][0]:
                            globals.instance.set("Strip[" + str(i) + "].device.mme", configure.local.getInputs()[output][0])
                        i = i + 1
                    n = n + 1
                        
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
                    globals.instance.inputs[0].A2 = True
                    globals.instance.inputs[1].A3 = True
                    globals.instance.inputs[2].A4 = True
                    globals.instance.inputs[3].A5 = True
                    globals.instance.inputs[4].B1 = True
                if globals.instance.inputs[0].A2 != True:
                    doPlugnPlay()
                if globals.instance.inputs[1].A3 != True:
                    doPlugnPlay()
                if globals.instance.inputs[2].A4 != True:
                    doPlugnPlay()
                if globals.instance.inputs[3].A5 != True:
                    doPlugnPlay()
                if globals.instance.inputs[4].B1 != True:
                    doPlugnPlay()            
                vm.changed = False
    
    class vban:
        clientsOld = []
        
        def getDaisyChain():
            return pytools.IO.getJson("daisyChain.json")["chain"]
        
        def setValues(skip=False):
            clients = configure.vban.getDaisyChain()
            
            if (clients != configure.vban.clientsOld) or skip:
            
                if clients[0]:
                    i = 0
                    n = 0
                    outputs = configure.local.getOutputs(onlyExtras=True)
                    for output in outputs:
                        if (globals.id * 5) < n < ((globals.id + 1) * 5):
                            globals.instance.set("vban.instream[" + str(i) + "].name", "Stream" + output[0].upper() + output[1:])
                            globals.instance.set("vban.instream[" + str(i) + "].ip", clients[0])
                            globals.instance.set("vban.instream[" + str(i) + "].port", 6980 + globals.id)
                            globals.instance.set("vban.instream[" + str(i) + "].route", i + 1)
                            globals.instance.set("vban.instream[" + str(i) + "].on", 1)
                            globals.instance.set("vban.outstream[" + str(i) + "].name", "Stream" + output[0].upper() + output[1:])
                            globals.instance.set("vban.outstream[" + str(i) + "].ip", clients[1])
                            globals.instance.set("vban.outstream[" + str(i) + "].port", 6980 + globals.id)
                            globals.instance.set("vban.outstream[" + str(i) + "].route", i + 1)
                            globals.instance.set("vban.outstream[" + str(i) + "].on", 1)
                            i = i + 1
                        n = n + 1
                
                if globals.instance.get("vban.Enable") != 1:
                    globals.instance.set("vban.Enable", 1)
                    
                configure.vban.clientsOld = clients
            
    def handler():
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
                time.sleep(30)
            except:
                print(traceback.format_exc())
                time.sleep(1)
            

runStuff = False
try:
    for arg in sys.argv:
        if arg.split("=")[0] == "--id":
            globals.id = int(arg.split("=")[1])
        if arg == "--run":
            runStuff = True
except:
    pass

if runStuff:
    threadVoicemeeter = threading.Thread(target=vm.handler)
    threadVConfigure = threading.Thread(target=configure.handler)
    threadVoicemeeter.start()
    threadVConfigure.start()