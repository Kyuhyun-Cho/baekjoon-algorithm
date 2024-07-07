import sys
from collections import deque

#sys.stdin = open("input.txt")

m, n = map(int, sys.stdin.readline().split())

graph = []
visited = [[False] * (m) for _ in range(n)]
broken = [[0] * (m) for _ in range(n)]

for _ in range(n):
    lst = list(map(int, sys.stdin.readline().rstrip()))
    graph.append(lst)

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(y, x):
    queue = deque([(y, x)])
    visited[y][x] = True

    while queue:
        py, px = queue.popleft()

        for i in range(4):
            ny = py + dy[i]
            nx = px + dx[i]

            if 0 <= ny < n and 0 <= nx < m:

                if visited[ny][nx] == False:
                    if graph[ny][nx] == 0:
                        broken[ny][nx] = broken[py][px]
                        queue.appendleft((ny, nx))  # 벽이 없는 곳을 우선적으로 돌도록 appendleft 해준다
                        visited[ny][nx] = True

                    # 벽이 없는 곳을 우선적으로 돌 수 있도록 appendleft 해주면 나중에 벽을 부순 자리에서
                    # 다른 곳으로 이동하려고 해도 이미 벽이 없는 곳을 지나다니면서 방문처리가 되어있기 때문에
                    # 어차피 벽을 부순 자리에서 다른 곳으로 확장하여 이동할 수가 없다. 
                    # 만약 벽에 가로막혀 아직 방문하지 못한 곳이 있는데, 만약 그 곳이 벽을 부순 자리와 인접한 자리라면
                    # append로 넣어놨던 벽을 부순 좌표에서 확장하여 갈 수 있고, 다시 말해 그 자리는 벽을 부셔야만 갈 수 있는 자리라고 판단할 수 있다.

                    elif graph[ny][nx] == 1:
                        broken[ny][nx] = broken[py][px] + 1
                        queue.append((ny, nx))
                        visited[ny][nx] = True


bfs(0, 0)

print(broken[n-1][m-1])