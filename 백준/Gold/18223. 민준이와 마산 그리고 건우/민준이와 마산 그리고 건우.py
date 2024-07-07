import sys
import heapq
import math

INF = float("inf")

#sys.stdin = open("input.txt")

v, e, p = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(v+1)]
distance = [INF] * (v+1)
visited = [[] for _ in range(v+1)]

for _ in range(e):
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
                heapq.heappush(q, (cost, next_node))
               

dijkstra(1)

minjun_to_masan= distance[v]
minjun_to_gunwoo = distance[p]

dijkstra(p)

gunwoo_to_masan = distance[v]

if minjun_to_gunwoo + gunwoo_to_masan == minjun_to_masan:
    print("SAVE HIM")
else:
    print("GOOD BYE")

