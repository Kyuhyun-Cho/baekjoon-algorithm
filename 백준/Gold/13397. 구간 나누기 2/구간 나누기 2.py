import sys
import math

#sys.stdin = open("input.txt")

n, m = map(int, sys.stdin.readline().split())

lst = list(map(int, sys.stdin.readline().split()))

start = 0
end = max(lst)

answer = float("inf")

while start <= end:
    mid = (start+end)//2
    
    cnt = 1

    max_val = lst[0]
    min_val = lst[0]

    for i in range(len(lst)):
        max_val = max(max_val, lst[i])
        min_val = min(min_val, lst[i])
        
    
        if max_val - min_val > mid:
            cnt += 1
            max_val = lst[i]
            min_val = lst[i]

    if cnt <= m:
        end = mid-1
        answer = min(answer, mid)

    else:
        start = mid+1

print(answer)