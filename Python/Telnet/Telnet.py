import telnetlib
import threading
import time

def listening():
	HOST = "midnightsun2.org"
	global tn
	tn = telnetlib.Telnet(HOST)
	while bRun:
		strMessage = tn.read_very_eager().decode('ascii')
		if (strMessage):
			print(strMessage)
		

def userInput():
	while bRun:
		strInput = raw_input()
		strInput = analyzeInput(strInput)
		tn.write(strInput.encode('ascii') + b"\n")


def analyzeInput(strInput):
	if strInput == "strich":
		print ("That's my name!")
	
	return strInput	


global bRun 
bRun = True
tListening = threading.Thread(target = listening)
tListening.start()
tUserInput = threading.Thread(target = userInput)
tUserInput.start()



