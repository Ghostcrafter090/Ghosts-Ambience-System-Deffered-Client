import os
import sys
import traceback

class tools:
    def getFile(path, doPrint=True):
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
    
packagesDirty = tools.getFile(".\\drivers\\python\\pip.install").split("\n")
packages = []
for package in packagesDirty:
    if package.split(" ")[0] not in packages:
        packages.append(package.split(" ")[0])
for package in packages:
    os.system("py -m pip install " + package.split(" ")[0])

try:
    import modules.pytools as pytools
except:
    print(traceback.format_exc())
    input()
