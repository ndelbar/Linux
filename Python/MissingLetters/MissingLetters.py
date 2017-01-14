import string

strMessage = raw_input("Enter a string:").lower()

for eachChar in list(string.ascii_lowercase):
	if eachChar not in strMessage:
		print eachChar,
