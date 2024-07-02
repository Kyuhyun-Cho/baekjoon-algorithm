import sys
from collections import deque

#sys.stdin = open("input.txt")

n, k = map(int, sys.stdin.readline().split())

queue = deque([(n,0)])
visited = [0] * 1000000

while queue:
    current, cnt = queue.popleft()

    if current == k:
        print(cnt)
        break

    back = current-1
    front = current+1
    jump = current*2

    if 0 <= back <= 100000 and visited[back] == 0:
        queue.append((current-1, cnt+1))
        visited[back] = 1

    if 0 <= front <= 100000 and visited[front] == 0:
        queue.append((current+1, cnt+1))
        visited[front] = 1

    if 0 <= jump <= 100000 and visited[jump] == 0:
        queue.append((current*2, cnt+1))
        visited[jump] = 1
    

