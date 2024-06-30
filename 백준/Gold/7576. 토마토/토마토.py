import sys
from collections import deque

#sys.stdin = open("input.txt")

m, n = map(int, sys.stdin.readline().split())

graph = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
visited = [[0] * m for _ in range(n)]

queue = deque()

for i in range(n):
    for j in range(m):
        if graph[i][j] == 1:
            queue.append((i, j, 1))

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs():
    while queue:
        y, x, cnt = queue.popleft()

        graph[y][x] = cnt

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < n and 0 <= nx < m:
                if graph[ny][nx] == 0 and visited[ny][nx] == 0:
                    queue.append((ny, nx, cnt+1))
                    visited[ny][nx] = 1

bfs()

answer = 0

for i in range(n):
    for j in range(m):
        if graph[i][j] == 0:
            answer = -1
            break

        answer = max(answer, graph[i][j]-1)

    if answer == -1:
        break

print(answer)

