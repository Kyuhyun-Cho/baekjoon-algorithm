import sys

n, m  = map(int, sys.stdin.readline().split())

s = set()
for i in range(n):
	str = input()
	s.add(str)

cnt = 0
for i in range(m):
	str = input()
	if str in s:
		cnt += 1

print(cnt)