import sys
from collections import deque

# sys.stdin = open("input.txt")

n, m = map(int, sys.stdin.readline().split())

graph = [0] * (n+1)
visited = [[0] * (m+1) for _ in range(n+1)]

for i in range(1, n+1):
    graph[i] = '0' + sys.stdin.readline().rstrip()

queue = deque()
queue.append([1, 1, 1])
visited[1][1] = 1

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

# for i in range(len(graph)):
#     print(graph[i])
# print()

while queue:
    py, px, cnt = queue.popleft()
    
    # for i in range(len(visited)):
    #     print(visited[i])
    # print()

    for i in range(4):
        ny = py + dy[i]
        nx = px + dx[i]
        if 1 <= ny <= n and 1 <= nx <= m:
            if graph[ny][nx] != '0' and visited[ny][nx] == 0:
                queue.append([ny, nx, cnt+1])
                visited[ny][nx] = cnt+1


print(visited[n][m])


