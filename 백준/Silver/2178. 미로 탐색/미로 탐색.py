import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
graph = list(sys.stdin.readline().rstrip() for _ in range(n))
visited = [[0] * m for _ in range(n)]

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(y, x, cnt):
    queue = deque([(y, x, cnt)])
    visited[y][x] = cnt

    while queue:
        py, px, pcnt = queue.popleft()

        for i in range(4):
            ny = py + dy[i]
            nx = px + dx[i]
            ncnt = pcnt + 1

            if (0 <= ny < n and 0 <= nx < m):
                if (graph[ny][nx] == '1' and visited[ny][nx] == 0):
                    queue.append((ny, nx, ncnt))
                    visited[ny][nx] = ncnt
            
bfs(0,0,1)

print(visited[n-1][m-1])
    