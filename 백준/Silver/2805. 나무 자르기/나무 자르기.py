import sys

#sys.stdin = open("input.txt")

n, m = map(int, sys.stdin.readline().split())

lst = list(map(int, sys.stdin.readline().split()))

start = 0
end = max(lst)
answer = 0

while start <= end:
    mid = (start+end)//2

    cnt = 0

    for tree in lst :
        # if tree <= mid:
        #     break

        # tree = max((tree - mid), 0)
            # cnt += tree
        if tree > mid:
            cnt += tree - mid

        # if cnt >= m:
        #     start = mid + 1
        #     answer = mid
        #     break
    
    if cnt >= m:
        start = mid + 1
        answer = mid

    elif cnt < m:
        end = mid - 1

print(answer)