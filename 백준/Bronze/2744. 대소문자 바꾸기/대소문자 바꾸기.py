for i in input():
	if(i.isupper()):
		print(i.lower(), end='')
	elif(i.islower()):
		print(i.upper(), end='')