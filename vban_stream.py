import modules.audio as audio
import vm
import modules.pytools as pytools
import modules.vban as vban
import modules.logManager as log

import os
import sys
import time
import subprocess
import traceback

import random

import psutil

def checkRunningOld():
    check = subprocess.getoutput("tasklist | findstr \"vbanStream_" + str("window") + ".exe\"").split("\n") # "streams.vbanStream.speakerType"
    if "" in check:
        check.remove("")
        
    return len(check)

def checkRunning():
    return [p.name() for p in psutil.process_iter()].count("vbanStream_" + str(streams.vbanStream.speakerType) + ".exe")

def getMinimum(check):
    streams.minimumCounts = pytools.IO.getJson("minimumStreamCounts.json")
    if type(streams.minimumCounts) != dict:
        streams.minimumCounts = {
            "clock": 2,
            "fireplace": 2,
            "window": 2,
            "outside": 2,
            "porch": 2,
            "generic": 2,
            "light": 2
        }
        
    streamMinimum = streams.minimumCounts[streams.vbanStream.speakerType]
    
    if (check % streamMinimum) != 0:
        print("Calculating minimum...")
        startCheck = -1
        endCheck = -2
        while (startCheck != endCheck):
            startCheck = checkRunning()
            os.system("start \"\" \"vbanStream_" + streams.vbanStream.speakerType + ".exe\" -c \"import time; time.sleep(2)\"")
            midCheck = checkRunning()
            time.sleep(3)
            endCheck = checkRunning()
            
        streamMinimum = midCheck - startCheck
        streams.minimumCounts = pytools.IO.getJson("minimumStreamCounts.json")
        streams.minimumCounts[streams.vbanStream.speakerType] = streamMinimum
        pytools.IO.saveJson("minimumStreamCounts.json", streams.minimumCounts)
        
    return streamMinimum

print = log.printLog

class streams:
    vbanStream = False
    minimumCounts = {
        "clock": 1,
        "fireplace": 1,
        "window": 1,
        "outside": 1,
        "porch": 1,
        "generic": 1,
        "light": 1
    }

def setup(speakerType, clients, serverHostname):
    outputs = vm.configure.local.getOutputs()
    pytools.IO.saveJson(".\\soundOutputs.json", outputs)

    audio.tools.setOutputs(noSleep=True)

    streams.vbanStream = vban.speaker(speakerType, clients[0], clients[1])
    
    streams.vbanStream.serverHostname = serverHostname
    
def run():
    
    check = -1
    while check == -1:
        try:
            check = checkRunning()
        except:
            pass
    
    i = 0
    while ((check / getMinimum(check)) > 1) and (i < random.randint(5, 15)):
        print("Streams already running. Count: " + str(check) + ". Minimum: " + str(getMinimum(check)))
        check = -1
        while check == -1:
            try:
                check = checkRunning()
            except:
                pass
            
            time.sleep(random.random())
        i = i + 1
        time.sleep(random.random())
        
    if (check / getMinimum(check)) <= 1:
        streams.vbanStream.run()
        while True:
            print("Handler is alive.")
            time.sleep(1)
    else:
        
        print("Streams already running. Count: " + str(check) + ". Minimum: " + str(getMinimum(check)))

clients = [False, "localhost"]
speakerType = "clock"
serverHostname = "0.0.0.0"
doRun = False

if __name__ == "__main__":
    for arg in sys.argv:
        if arg.split("=")[0] == "--clients":
            clients = arg.split("=")[1].split(',')
            if clients[0] == "False":
                clients[0] = False
        if arg.split("=")[0] == "--speakerType":
            speakerType = arg.split("=")[1]
        if arg.split("=")[0] == "--hostname":
            serverHostname = arg.split("=")[1]
        if arg == "--run":
            doRun = True

    try:
        setup(speakerType, clients, serverHostname)

        if doRun:
            run()
    except:
        print(traceback.format_exc())

# py vban_stream.py --run --clients=False,192.168.2.30 --speakerType=fireplace --hostname=192.168.2.30 