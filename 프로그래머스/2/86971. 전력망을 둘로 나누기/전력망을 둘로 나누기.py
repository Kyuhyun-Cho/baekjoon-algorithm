def solution(n, wires):
    answer = 0
    gap = 99999
    

    total_sum = 0
    total_cnt = 0
    
    def dfs(graph, node, visited):
        nonlocal total_sum, total_cnt
        
        visited[node] = 1
        total_sum += node
        total_cnt += 1
        
        for next_node in graph[node]:
            if visited[next_node] == 0:
                dfs(graph, next_node, visited)
        
        
    for i in range(n-1):
        
        total_sum_list = []
        total_cnt_list = []

        graph = [[] for _ in range(n+1)]
        visited = [0] * (n+1)

        for j in range(n-1):
            if j == i:
                continue
            
            u = wires[j][0]
            v = wires[j][1]
    
            graph[u].append(v)
            graph[v].append(u)
        
        for i in range(1, n+1):
            
            if visited[i] == 0:
                
                total_sum = 0
                total_cnt = 0
                
                dfs(graph, i, visited)

                total_sum_list.append(total_sum)
                total_cnt_list.append(total_cnt)
                
#                 print(i, visited)
                

#         print(total_sum_list, total_cnt_list)
#         print("------------------------------")
        if abs(total_cnt_list[0]-total_cnt_list[1]) < gap:
            gap = abs(total_cnt_list[0]-total_cnt_list[1])
        
    return gap