def solution(n, computers):
    answer = 0
        
    visited = [0] * n

    def dfs(v):
        visited[v] = 1
               
        for i in range(len(computers[v])):
            if computers[v][i] == 1 and visited[i] == 0:
                visited[i] = 1
                dfs(i)
    
    for i in range(n):
        if visited[i] == 0:
            dfs(i)
            answer += 1
                    
    return answer