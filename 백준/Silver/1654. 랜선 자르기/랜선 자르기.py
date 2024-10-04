import sys

k, n = map(int, sys.stdin.readline().split())

lst = []

for i in range(k):
    tmp = int(sys.stdin.readline().rstrip())
    lst.append(tmp)

left = 1
right = max(lst)
mid = (left+right)//2

answer = 0

while left <= right:
    mid = (left+right)//2

    cnt = 0

    for length in lst:
        cnt += length//mid

    if cnt >= n:
        answer = mid
        left = mid + 1

    else:
        right = mid - 1

    
print(answer)