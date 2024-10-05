from collections import deque

def solution(maps):
    answer = 0
    
    n = len(maps)
    m = len(maps[0])
    
    maps = [ list(maps[i]) for i in range(n)]
    visited = [[0] * m for _ in range(n)]
    
    sy, sx = 0, 0
    ly, lx = 0, 0
    ey, ex = 0, 0
    
    for i in range(n):
        for j in range(m):
            if maps[i][j] == 'S':
                sy, sx = i, j
            elif maps[i][j] == 'L':
                ly, lx = i, j
            elif maps[i][j] == 'E':
                ey, ex = i, j
                
    # print(sy, sx)
    # print(ly, lx)
    # print(ey, ex)
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]
    
    def bfs(y, x, cnt, ey, ex):
        queue = deque([(y, x, 0)])
        
        visited[y][x] = 1
        
        while queue:
            py, px, pcnt = queue.popleft()

            if py == ey and px == ex:
                return pcnt
            
            for i in range(4):
                ny = py + dy[i]
                nx = px + dx[i]
                
                if (0 <= ny < n and 0 <= nx < m and visited[ny][nx] == 0):
                    if (maps[ny][nx] == 'O' or maps[ny][nx] == 'L' or maps[ny][nx] == 'E' or maps[ny][nx] == 'S'):
                        queue.append((ny, nx, pcnt+1))
                        visited[ny][nx] = 1
        return -1
        
    cnt_1 = bfs(sy, sx, 0, ly, lx)
    visited = [[0] * m for _ in range(n)]
    cnt_2 = bfs(ly, lx, 0, ey, ex)
    
    if cnt_1 == -1 or cnt_2 == -1:
        return -1
    
    answer = cnt_1 + cnt_2
    
    return answer