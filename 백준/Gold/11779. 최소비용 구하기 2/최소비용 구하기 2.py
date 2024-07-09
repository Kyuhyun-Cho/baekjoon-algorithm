import sys
import heapq
import math

INF = float("inf")

#sys.stdin = open("input.txt")

n = int(sys.stdin.readline().rstrip())
m = int(sys.stdin.readline().rstrip())

graph = [[] for _ in range(n+1)]
distance = [INF] * (n+1)

for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a].append((b, c))

start_city, end_city = map(int, sys.stdin.readline().split())

nearest = [start_city] * (n+1)

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
                

dijkstra(start_city)
print(distance[end_city])

path = []
tmp = end_city

while tmp != start_city:
    path.append(tmp)
    tmp = nearest[tmp]

path.append(start_city)
path.reverse()

print(len(path))
print(' '.join(map(str, path)))

