import sys

# sys.stdin = open("input.txt")

n = int(sys.stdin.readline().rstrip())

a_list = list(map(int, sys.stdin.readline().split()))
b_list = list(map(int, sys.stdin.readline().split()))

a_list.sort()
b_list.sort(reverse=True)

answer = 0

for a, b in zip(a_list, b_list):
    answer += a*b

print(answer)
