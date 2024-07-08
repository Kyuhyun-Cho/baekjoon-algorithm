import sys
import heapq
import math

INF = float("inf")

#sys.stdin = open("input.txt")
idx = 1

while True:
    n = int(sys.stdin.readline().rstrip())

    if n == 0:
        break

    graph = []
    distance = [[INF] * n for _ in range(n)]

    for _ in range(n):
        lst = list(map(int, sys.stdin.readline().split()))
        graph.append(lst)

    dy = [1, 0, -1, 0]
    dx = [0, 1, 0, -1]

    def dijkstra(y, x):
        q = []

        heapq.heappush(q, (graph[0][0], (y, x)))
        distance[y][x] = graph[0][0]
        
        while q:
            cost, now = heapq.heappop(q)
            py = now[0]
            px = now[1]
            
            if distance[py][px] < cost:
                continue

            for i in range(4):
                ny = py + dy[i]
                nx = px + dx[i]
                
                if 0 <= ny < n and 0 <= nx < n:
                    ncost = cost + graph[ny][nx]

                    if ncost < distance[ny][nx]:
                        distance[ny][nx] = ncost
                        heapq.heappush(q, (ncost, (ny, nx)))
        


    dijkstra(0, 0)

    print(f"Problem {idx}: {distance[n-1][n-1]}")
    idx += 1
             