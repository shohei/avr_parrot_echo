import serial
import threading
import sys

s = serial.Serial(port="/dev/tty.usbmodem1411",baudrate=9600)

def thread2():
    while True:
        data = s.read()
        sys.stdout.write(data)

t2 = threading.Thread(target=thread2)
t2.start()

print "Press <Enter> to exit."
print "Wait a moment for initializing......"
while(True):
    try:
        key = raw_input()
        if(key==""):
            t2._Thread__stop()
            exit()
        key += "\n"
        s.write(key)
    except:
        print "\nstop thread2"
        t2._Thread__stop()
        exit()

