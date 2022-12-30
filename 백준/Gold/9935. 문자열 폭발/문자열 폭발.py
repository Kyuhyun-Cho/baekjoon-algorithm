str = input().rstrip()
bomb = input().rstrip()
stack = []

for char in str:
	stack.append(char)
	if len(stack) >= len(bomb) and ''.join(stack[len(stack)-len(bomb):]) == bomb:
		for i in range(len(bomb)):
			stack.pop()
		
if(len(stack) == 0):
	print("FRULA")
else:
	print(''.join(stack))