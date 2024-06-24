import sys

# sys.stdin = open("input.txt")

n = int(sys.stdin.readline().rstrip())

p = list(map(int, sys.stdin.readline().split()))
p.sort()

answer = 0

for time in p:
    answer += time * n
    n -= 1

print(answer)
