num = int(input())
ls = []
for i in range(num):
	info = input().split()
	# print(info)
	ls.append(info)

ls.sort(key = lambda x :(-int(x[1]), int(x[2]), -int(x[3]), x[0]))
for i in range(num):
	print(ls[i][0])