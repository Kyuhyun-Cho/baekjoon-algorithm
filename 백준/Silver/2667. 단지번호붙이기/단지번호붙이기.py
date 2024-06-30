import sys
from collections import deque

#sys.stdin = open("input.txt")

n = int(sys.stdin.readline().rstrip())

graph = []
visited = [[0] * n for _ in range(n)]

for i in range(n):
    graph.append(list(map(int, sys.stdin.readline().rstrip())))

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(y, x):
    queue = deque([(y, x)])
    visited[y][x] = 1
    cnt = 1

    while queue:
        y, x = queue.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < n and 0 <= nx < n:
                if graph[ny][nx] == 1 and visited[ny][nx] == 0:
                    queue.append((ny, nx))
                    visited[ny][nx] = 1
                    cnt += 1
    return cnt
    
answer = 0

cnt_list = []

for i in range(n):
    for j in range(n):
        if graph[i][j] == 1 and visited[i][j] == 0:
            cnt_list.append(bfs(i, j))

print(len(cnt_list))

cnt_list.sort()
for cnt in cnt_list:
    print(cnt)