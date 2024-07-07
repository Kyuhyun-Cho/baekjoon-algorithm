import sys
import heapq
import math

INF = float("inf")

#sys.stdin = open("input.txt")

n, e = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n+1)]
distance = [INF] * (n+1)

for _ in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

v1, v2 = map(int, sys.stdin.readline().split())

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

first = [1, v1, v2, n]
second = [1, v2, v1, n]

first_dist = 0
second_dist = 0

for i in range(len(first)-1):
    dijkstra(first[i])
    first_dist += distance[first[i+1]]
    distance = [INF] * (n+1)

for i in range(len(second)-1):
    dijkstra(second[i])
    second_dist += distance[second[i+1]]
    distance = [INF] * (n+1)

answer = min(first_dist, second_dist)

if answer == INF:
    print(-1)
else:
    print(answer)