from collections import deque

def solution(board):
    answer = 0
    
    n, m = len(board), len(board[0])
    visited = [[0] * m for _ in range(n)]
    
    sy, sx = 0, 0
    ey, ex = 0, 0
    
    for i in range(n):
        for j in range(m):
            if board[i][j] == 'R':
                sy, sx = i, j
            elif board[i][j] == 'G':
                ey, ex = i, j
    
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]
    
    def bfs(y, x, cnt):
        nonlocal answer
        
        queue = deque([(y, x, cnt)])
        
        visited[y][x] = 1
        
        while queue:
            if answer == -1:
                break
            
            py, px, pcnt = queue.popleft()
            
            if board[py][px] == 'G':
                answer = 1
                break
            
            for i in range(4):
                ny = py
                nx = px
                
                while True:
                    ny += dy[i]
                    nx += dx[i]                

                    if ny < 0 or nx < 0 or n <= ny or m <= nx or board[ny][nx] == 'D':
                        ny -= dy[i]
                        nx -= dx[i]
                        break
                
                if ny == py and nx == px:
                    continue
                
                if 0 <= ny < n and 0 <= nx < m and visited[ny][nx] == 0:
                    queue.append((ny, nx, pcnt+1))
                    visited[ny][nx] = pcnt + 1
                    
        if answer != 1:
            answer = -1
    
    bfs(sy, sx, 0)
    
    # for i in visited:
    #     print(i)
    
    if answer == -1:
        return -1
    else:
        return visited[ey][ex]
    
    return answer