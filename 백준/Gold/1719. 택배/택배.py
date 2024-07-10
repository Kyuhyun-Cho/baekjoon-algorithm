import sys
import heapq
import math

INF = float("inf")

#sys.stdin = open("input.txt")

n, m = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n+1)]
distance = [INF] * (n+1)
nearest = ['-'] * (n+1)
table = [['-'] * (n+1) for _ in range(n+1)]

for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

def dijkstra(start):
    q = []

    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)

        if distance[now] < dist:
            continue
            
        for next_node, next_dist in graph[now]:
            cost = dist + next_dist

            if cost < distance[next_node]:
                distance[next_node] = cost
                nearest[next_node] = now
                heapq.heappush(q, (cost, next_node))

for i in range(1, n+1):
    distance = [INF] * (n+1)
    dijkstra(i)

    for j in range(1, n+1):
        path = []
        now = j

        while now != i:
            path.append(now)
            now = nearest[now]
        
        path.reverse()
        
        if i != j:
            table[i][j] = path[0]
        
for i in range(1, n+1):
    for j in range(1, n+1):
        print(table[i][j], end=' ')
    print()