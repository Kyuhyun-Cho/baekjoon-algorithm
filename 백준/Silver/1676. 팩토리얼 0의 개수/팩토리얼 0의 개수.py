n = int(input())
answer = 1
num = 1
for i in range(1,n+1):
	num *= i
str_num = str(num)

while(True):
	if (str_num[answer * -1] == '0'):
		answer += 1
	else:
		break	
print(answer-1)