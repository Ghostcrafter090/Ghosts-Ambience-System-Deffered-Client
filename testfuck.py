import sys
import atexit
import signal
import traceback

def exit_handler():
    print("Audio Engine Instance Has Exited.")
    
def exception_handler(exc_type, exc_value, exc_traceback):
    if issubclass(exc_type, KeyboardInterrupt):
        sys.__excepthook__(exc_type, exc_value, exc_traceback)
        return

    print("Uncaught exception")
    print('Type:', exc_type)
    print('Value:', exc_value)
    print('Traceback:', exc_traceback)

sys.excepthook = exception_handler

def kill_handler(*args):
    sys.exit(0)

atexit.register(exit_handler)
signal.signal(signal.SIGINT, kill_handler)
signal.signal(signal.SIGTERM, kill_handler)

# MAIN PROGRAM
# for example just reading from the input:
input("Press enter: ")
try:
    penis
except:
    print("penis")