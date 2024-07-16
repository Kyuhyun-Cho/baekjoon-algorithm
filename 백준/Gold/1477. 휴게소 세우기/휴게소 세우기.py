import sys
import math

#sys.stdin = open("input.txt")

n, m, l = map(int, sys.stdin.readline().split())

lst = list(map(int, sys.stdin.readline().split()))
lst.append(0)
lst.append(l)
lst.sort()

start = 1
end = l
answer = 0

while start <= end:
    mid = (start+end)//2
    cnt = 0
   
    for i in range(1, len(lst)):
        if lst[i] - lst[i-1] > mid:
            cnt += (lst[i] - lst[i-1] - 1) // mid

    if cnt > m:
        start = mid + 1
    else:
        end = mid - 1
        answer = mid

print(answer)