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
    start_city, end_city, cost = map(int, sys.stdin.readline().split())
    graph[start_city].append((end_city, cost))

start, end = map(int, sys.stdin.readline().split())

def dijkstra(start):
    q = []

    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)

        if distance[now] < dist:
            continue

        for end in graph[now]:
            cost = dist + end[1]

            if cost < distance[end[0]]:
                distance[end[0]] = cost
                heapq.heappush(q, (cost, end[0]))

dijkstra(start)

print(distance[end])