import sys

#sys.stdin = open("input.txt")

k, n = map(int, sys.stdin.readline().split())

lst = []

for _ in range(k):
    lst.append(int(sys.stdin.readline().rstrip()))

start = 1
end = max(lst)

answer = 0

while start <= end:
    mid = (start+end)//2

    cnt = 0

    for i in range(k):
        cnt += lst[i]//mid

    if cnt >= n:
        start = mid + 1
        answer = mid

    else:
        end = mid - 1

print(answer)