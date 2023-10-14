import modules.pytools as pytools
import os
import urllib.parse
import json
import time
import sys

for host in pytools.IO.getJson("hosts.json")["hosts"]:
    print("[" + host + "] Updating host ...")
    os.system("xcopy .\\client.py \\\\" + host + "\\ambience_client /c /y")
    os.system("xcopy .\\vm.py \\\\" + host + "\\ambience_client /c /y")
    os.system("xcopy .\\run.bat \\\\" + host + "\\ambience_client /c /y")
    os.system("xcopy .\\disableanti.ps1 \\\\" + host + "\\ambience_client /c /y")
    os.system("xcopy .\\badaudio.ps1 \\\\" + host + "\\ambience_client /c /y")
    os.system("xcopy .\\modules\\* \\\\" + host + "\\ambience_client\\modules /c /y")
    os.system("robocopy \".\\sound\\assets\" \"\\\\" + host + "\\ambience_client\\sound\\assets\" /mir /w:1 /r:1 /S")
    try:
        if sys.argv[1] != "--skipRestart":
            error = 0
            while error < 10:
                try:
                    pytools.net.getJsonAPI("http://" + host + ":4507?json=" + urllib.parse.quote(json.dumps({
                        "command": "restart"
                    })), timeout=3)
                    print("[" + host + "] Sent restart command.")
                    break
                except:
                    print("[" + host + "] Not responding.")
                    error = error + 1
                    time.sleep(1)
            if error >= 10:
                print("[" + host + "] Is not responding. Please check connection status.")
    except:
        error = 0
        while error < 10:
            try:
                pytools.net.getJsonAPI("http://" + host + ":4507?json=" + urllib.parse.quote(json.dumps({
                    "command": "restart"
                })), timeout=3)
                print("[" + host + "] Sent restart command.")
                break
            except:
                print("[" + host + "] Not responding.")
                error = error + 1
                time.sleep(1)
        if error >= 10:
            print("[" + host + "] Is not responding. Please check connection status.")
        