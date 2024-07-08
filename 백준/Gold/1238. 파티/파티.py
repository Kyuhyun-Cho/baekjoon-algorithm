import sys
import heapq

INF = float("inf")

#sys.stdin = open("input.txt")

n, m, x = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n+1)]
distance = [INF] * (n+1)

for _ in range(m):
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

        for next_node, next_dist in graph[now]:
            cost = dist + next_dist

            if cost < distance[next_node]:
                distance[next_node] = cost
                heapq.heappush(q, (cost, next_node))

time_list = []

for i in range(1, n+1):
    dijkstra(i)
    first = distance[x]
    distance = [INF] * (n+1)

    dijkstra(x)
    second = distance[i]
    distance = [INF] * (n+1)

    time_list.append(first+second)

print(max(time_list))