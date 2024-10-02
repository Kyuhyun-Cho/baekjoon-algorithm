from collections import deque


def solution(maps):
    answer = 0
    
    height = len(maps)
    width = len(maps[0])
    
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]

    visited = [[-1] * width for _ in range(height)]

    queue = deque([(0,0,1)])
    
    visited[0][0] = 1
    
    while queue:
        py, px, pcnt = queue.popleft()
        ncnt = pcnt+1
        
        for i in range(4):
            ny = py + dy[i]
            nx = px + dx[i]
            
            if 0 <= ny < height and 0 <= nx < width:
                if maps[ny][nx] == 1 and visited[ny][nx] == -1:
                    
                    queue.append((ny, nx, ncnt))
                    visited[ny][nx] = ncnt
                    
                    
    answer = visited[height-1][width-1]
    
    # for i in visited:
    #     print(i)
    
    return answer