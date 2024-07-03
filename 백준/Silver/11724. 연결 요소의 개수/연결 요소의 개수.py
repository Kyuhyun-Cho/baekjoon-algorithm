import sys
sys.setrecursionlimit(10**6)
# sys.stdin = open("input.txt")

def dfs(graph, v, visited):
    visited[v] = 1
    for i in graph[v]:
        if visited[i] == 0:
            dfs(graph, i, visited)

n, m = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n+1)]
visited = [0] * (n+1)

for i in range(m):
    u, v = map(int, sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)

answer = 0

for i in range(1, n+1):
    if visited[i] == 0:
        dfs(graph, i, visited)
        answer += 1

print(answer)

