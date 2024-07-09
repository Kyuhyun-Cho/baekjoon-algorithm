import sys
import heapq
import math

INF = float("inf")

#sys.stdin = open("input.txt")

n, m, r = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n+1)]
distance = [INF] * (n+1)
item = list(map(int, sys.stdin.readline().split()))

for _ in range(r):
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

answer_list = []

for i in range(1, n+1):
    dijkstra(i)

    tmp = 0

    for j in range(1, len(distance)):
        if distance[j] <= m:
            tmp += item[j-1]
    
    answer_list.append(tmp)
    distance = [INF] * (n+1)

print(max(answer_list))