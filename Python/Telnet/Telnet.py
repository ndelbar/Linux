import telnetlib
import threading
import time

def listening():
	HOST = "midnightsun2.org"
	global tn
	tn = telnetlib.Telnet(HOST)
	while 1:
		strMessage = tn.read_very_eager().decode('ascii')
		if (strMessage):
			print(strMessage)
		

def userInput():
	while 1:
		strInput = raw_input()
		tn.write(strInput.encode('ascii') + b"\n")

tListening = threading.Thread(target = listening)
tListening.start()
tUserInput = threading.Thread(target = userInput)
tUserInput.start()



