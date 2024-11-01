import sys


r, c = map(int, sys.stdin.readline().split())
graph = [list(sys.stdin.readline().rstrip()) for _ in range(r)]
visited = [0] * 26

sy, sx = 0, 0

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

max_cnt = -1

def dfs(py, px, pcnt):
    global max_cnt

    if pcnt > max_cnt:
        max_cnt = pcnt
    
    for i in range(4):
        ny = py + dy[i]
        nx = px + dx[i]
        ncnt = pcnt + 1

        if 0 <= ny < r and 0 <= nx < c and visited[ord(graph[ny][nx])-65] == 0:
            visited[ord(graph[ny][nx])-65] = 1
            dfs(ny, nx, ncnt)
            visited[ord(graph[ny][nx])-65] = 0

visited[ord(graph[sy][sx])-65] = 1
dfs(sy, sx, 1)

print(max_cnt)
