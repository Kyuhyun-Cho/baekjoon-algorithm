import sys
from collections import deque

#sys.stdin = open("input.txt")

n = int(sys.stdin.readline().rstrip())

graph = [list(sys.stdin.readline()) for _ in range(n)]
visited = [[0] * n for _ in range(n)]

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(y, x):
    queue = deque([(y, x)])
    visited[y][x] = 1
    color = graph[y][x]

    while queue:
        py, px = queue.popleft()
        for i in range(4):
            ny = py + dy[i]
            nx = px + dx[i]

            if 0 <= ny < n and 0 <= nx < n:
                if graph[ny][nx] == color and visited[ny][nx] == 0:
                    queue.append((ny, nx))
                    visited[ny][nx] = 1

rgb_cnt = 0

for i in range(n):
    for j in range(n):
        if visited[i][j] == 0:
            bfs(i, j)
            rgb_cnt += 1

for i in range(n):
    for j in range(n):
        if graph[i][j] == 'G':
            graph[i][j] = 'R'

visited = [[0] * n for _ in range(n)]

rb_cnt = 0

for i in range(n):
    for j in range(n):
        if visited[i][j] == 0:
            bfs(i, j)
            rb_cnt += 1

print(rgb_cnt, rb_cnt)