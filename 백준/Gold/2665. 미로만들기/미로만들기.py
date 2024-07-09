import sys
from collections import deque

#sys.stdin = open("input.txt")

n = int(sys.stdin.readline().rstrip())

graph = []
visited = [[False] * n for _ in range(n)]
changed = [[0] * n for _ in range(n)]

for _ in range(n):
    lst = list(map(int, sys.stdin.readline().rstrip()))
    graph.append(lst)

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

def bfs(y, x):
    q = deque([(y, x)])
    visited[y][x] = True

    while q:
        py, px = q.popleft()

        for i in range(4):
            ny = py + dy[i]
            nx = px + dx[i]

            if 0 <= ny < n and 0 <= nx < n:
                if visited[ny][nx] == False:
                    if graph[ny][nx] == 1:
                        q.appendleft((ny, nx))
                        visited[ny][nx] = True
                        changed[ny][nx] = changed[py][px]

                    elif graph[ny][nx] == 0:
                        q.append((ny, nx))
                        visited[ny][nx] = True
                        changed[ny][nx] = changed[py][px] + 1

bfs(0, 0)

print(changed[n-1][n-1])