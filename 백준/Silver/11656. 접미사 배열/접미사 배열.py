str = input()
ls = []
for i in range(len(str)):
	ls.append(str[i:])
ls.sort()
for i in ls:
	print(i)