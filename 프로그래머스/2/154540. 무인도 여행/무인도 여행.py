from collections import deque

def solution(maps):
    answer = []
    
    n, m = len(maps), len(maps[0])
    visited = [[0] * m for _ in range(n)]
    
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]
    
    def bfs(y, x, total_cnt):
        queue = deque([(y, x)])
        
        visited[y][x] = 1
        
        while queue:
            py, px = queue.popleft()
            
            total_cnt += int(maps[py][px])
            
            for i in range(4):
                ny = py + dy[i]
                nx = px + dx[i]
                
                if 0 <= ny < n and 0 <= nx < m and visited[ny][nx] == 0:
                    if maps[ny][nx] != 'X':
                        queue.append((ny, nx))
                        visited[ny][nx] = 1
        
        return total_cnt
    
    for i in range(n):
        for j in range(m):
            if maps[i][j] != 'X' and visited[i][j] == 0:
                total = bfs(i, j, 0)
                answer.append(total)
    
    if not answer:
        answer.append(-1)    
    
    answer.sort()
    
    return answer