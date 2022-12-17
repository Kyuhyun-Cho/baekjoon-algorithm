num = input()
split_num = num.split('-')

for i in range(len(split_num)):
	split_num[i] = split_num[i].split('+')

for i in range(len(split_num)):
	for j in range(len(split_num[i])):
		split_num[i][j] = int(split_num[i][j]);

for i in range(len(split_num)):
	split_num[i] = sum(split_num[i])

answer = 0 

if(num[0] == '-'):
	answer -= split_num[0]
else:
	answer += split_num[0]

for i in range(1, len(split_num)):
	answer -= split_num[i]

print(answer)