import sys
from collections import deque

#sys.stdin = open("input.txt")

t = int(sys.stdin.readline().rstrip())

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(y, x):
    queue = deque([(y, x)])
    visited[y][x] = 1
    while queue:
        py, px = queue.popleft()
        for i in range(4):
            ny = py + dy[i]
            nx = px + dx[i]

            if 0 <= ny < n and 0 <= nx < m:
                if graph[ny][nx] == 1 and visited[ny][nx] == 0:
                    queue.append((ny, nx))
                    visited[ny][nx] = 1


for test_case in range(t):

    m, n, k = map(int, sys.stdin.readline().split())

    graph = [[0] * m for _ in range(n)]
    visited = [[0] * m for _ in range(n)]

    for i in range(k):
        x, y = map(int, sys.stdin.readline().split())
        graph[y][x] = 1

    cnt = 0

    for i in range(n):
        for j in range(m):
            if graph[i][j] == 1 and visited[i][j] == 0:
                bfs(i, j)
                cnt += 1

    print(cnt)