import sys
import heapq

#sys.stdin = open("input.txt")

INF = int(1e9)

v, e = map(int, sys.stdin.readline().split())

k = int(sys.stdin.readline().rstrip())

graph = [[] for _ in range(v+1)]
distance = [INF] * (v+1)

for _ in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a].append((b, c))

def dijkstra(start):
    q = []

    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)
        
        if distance[now] < dist:
            continue

        for i in graph[now]: # (b, c)
            cost = dist + i[1] # i[1] = 각 노드로 가는 간선 가중치

            if cost < distance[i[0]]: # i[0] = 각 노드의 번호
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

dijkstra(k)

for i in range(1, v+1):
    if distance[i] == INF:
        print("INF")
    else:
        print(distance[i])

