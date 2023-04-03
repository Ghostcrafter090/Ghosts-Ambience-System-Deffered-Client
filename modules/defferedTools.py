# import modules.pytools as pytools
import time
import threading
import random
import hashlib
import os
import modules.pytools as pytools

class benchmark:
    
    n = 0
    
    def add():
        if random.random() < 2:
            benchmark.n = benchmark.n + 1
    
    def get():
        listf = []
        
        while len(listf) < 25:
            startTic = round(time.time() * 1000000000)
            
            benchmark.n = 0
            while benchmark.n < 500:
                threading.Thread(target=benchmark.add).start()
                if random.random() < 0.00005:
                    os.system("echo measuring... > null")
                
            listf.append(1 / ((round(time.time() * 1000000000) - startTic) / 1000000000))
            
        return (sum(listf) / len(listf)) * 1000 * 2
    
    def getNumberOfPlugins(bench):
        a = 6.27107
        b = 0.0000352913
        c = -1.88022
        d = -35.3348
        
        return (a ** (b * bench - c)) + d

class cipher:
    def hash(data):
        while len(data) > 1000:
            dataNew = b''
            n = 0
            while n < len(data):
                dataNew = dataNew + hashlib.md5(data[n:n + 100]).digest()
                n = n + 100
            data = dataNew
        return hashlib.md5(data).digest()