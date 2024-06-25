import sys

#sys.stdin = open("input.txt")

n = int(sys.stdin.readline().rstrip())

rope_list = []

for i in range(n):
    rope = int(sys.stdin.readline().rstrip())
    rope_list.append(rope)

rope_list.sort()

answer = rope_list[0] * n

for i in range(1, n):
    answer = max(answer, rope_list[i]*(n-i))

print(answer)