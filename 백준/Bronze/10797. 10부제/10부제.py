num = input()
tmp = list(input().split())
answer = 0
for i in range(5):
	if num in tmp[i]:
		answer += 1
print(answer)