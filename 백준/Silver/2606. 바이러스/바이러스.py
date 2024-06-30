import sys

def dfs (graph, v, visited):
    visited[v] = 1
    for i in graph[v]:
        if visited[i] == 0:
            dfs(graph, i, visited)

#sys.stdin = open("input.txt")

n = int(sys.stdin.readline().rstrip())
e = int(sys.stdin.readline().rstrip())

graph = [[] for _ in range(n+1)]
visited = [0] * (n+1)

for i in range(e):
    start, end = map(int, sys.stdin.readline().split())
    graph[start].append(end)
    graph[end].append(start)

for i in range(1, n+1):
    graph[i].sort()

dfs(graph, 1, visited)

print(sum(visited)-1)


