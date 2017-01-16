import threading
import time

def worker1():
	while 1:
		print "Worker1"
		time.sleep(2)

def worker2():
	while 1:
		print"Worker2"
		time.sleep(3)

tW1 = threading.Thread(name = 'worker1', target = worker1)
tW2 = threading.Thread(name = 'worker2', target = worker2)

tW1.start()
tW2.start()
