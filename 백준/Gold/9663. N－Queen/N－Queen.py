import sys


n = int(sys.stdin.readline().rstrip())

maps = [[0] * n for _ in range(n)]

used_column = [False] * n
used_right  = [False] * (2*n-1)
used_left   = [False] * (2*n-1)

cnt = 0

def solve(k):
    global cnt

    if k == n:
        cnt += 1
        return

    for i in range(n):
        if used_column[i] is False and used_right[k+i] is False and used_left[(n-1)+k-i] is False:
            used_column[i]       = True
            used_right[k+i]      = True
            used_left[(n-1)+k-i] = True

            solve(k+1)

            used_column[i]       = False
            used_right[k+i]      = False
            used_left[(n-1)+k-i] = False

solve(0)

print(cnt)