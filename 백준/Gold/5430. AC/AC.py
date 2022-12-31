testCase = int(input())

for t in range(testCase):
	p = input()
	n = int(input())
	arr = input().split(',')
	arr[0] = arr[0][1:]
	arr[len(arr)-1] = arr[len(arr)-1][:-1]
	if (arr[0] == ''):
		del arr[0]
		
	pointer = 0
	pointer_step = 1
	error_msg = False
	for i in range(len(p)):
		if p[i] == 'R':
			if (pointer == 0):
				pointer = -1
				pointer_step = -1
			elif (pointer == -1):
				pointer = 0
				pointer_step = 1
				
		elif p[i] == 'D':
			if not arr:
				error_msg = True
				break
			else:
				del arr[pointer]

	if (error_msg):
		print("error")
		continue
		
	elif (len(arr) == 0):
		print('[]')
		
	else:
		print('[', end='')
		for i in range(len(arr)):
			if (i != len(arr)-1):
				print(arr[pointer], end='')
				print(',', end='')
				pointer += pointer_step
			else:
				print(arr[pointer], end='')
				print(']')
			