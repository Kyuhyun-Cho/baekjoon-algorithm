import sys

n = int(input())
s = set()

for _ in range(n):
	s.add(input())

arr = list(s)
arr.sort()
arr.sort(key=lambda x : len(x))

for i in range(len(arr)):
	print(arr[i])