import vm
import modules.pytools as pytools
import modules.audio as audio
import modules.vban as vban

import sys
import time

class streams:
    vbanStream = False

def setup(speakerType, clients, serverHostname):
    outputs = vm.configure.local.getOutputs()
    pytools.IO.saveJson(".\\soundOutputs.json", outputs)

    audio.tools.setOutputs()

    # clients = vm.configure.vban.getDaisyChain()

    # if vm.flags.manualReturn:
    #     clients[1] = vm.flags.manualReturn

    streams.vbanStream = vban.speaker(speakerType, clients[0], clients[1])
    
    streams.vbanStream.serverHostname = serverHostname
    
def run():
    streams.vbanStream.run()
    while True:
        print("Handler is alive.")
        time.sleep(1)

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

    setup(speakerType, clients, serverHostname)

    if doRun:
        run()

# py vban_stream.py --run --clients=False,127.0.0.1 --speakerType=fireplace --hostname=192.168.2.40 