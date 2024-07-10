import sys
import heapq
import math

INF = float("inf")

#sys.stdin = open("input.txt")

def dijkstra(start, graph, distance):
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

t = int(sys.stdin.readline().rstrip())

for testcase in range(t):
    n, d, c = map(int, sys.stdin.readline().split())

    graph = [[] for _ in range(n+1)]
    distance = [INF] * (n+1)

    for _ in range(d):
        a, b, s = map(int, sys.stdin.readline().split())

        graph[b].append((a, s))

    dijkstra(c, graph, distance)

    cnt = 0
    time = 0

    for i in range(1, len(distance)):
        if distance[i] != INF:
            cnt += 1
            time = max(distance[i], time)
      
    print(cnt, time)
 

        

