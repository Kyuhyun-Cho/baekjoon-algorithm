import sys
import heapq


n, k = map(int, sys.stdin.readline().split())

jewel_heap = []
bag_list = []

for i in range(n):
    m, v = (map(int, sys.stdin.readline().split()))
    heapq.heappush(jewel_heap, [m, v])

for i in range(k):
    c = int(sys.stdin.readline().rstrip())
    bag_list.append(c)

bag_list.sort()

answer = 0

tmp_bag = []

for bag_weight in bag_list:

    while jewel_heap and jewel_heap[0][0] <= bag_weight: # !!!!! heap에서 첫번째 원소는 무조건 min값! 트리 구조이기 때문에 첫번째 값이 최소인 것은 보장됨. 단 다음 인덱스부터는 형제 노드 간 대소 관계는 보장되지 않기 떄문에 알 수 없음
        heapq.heappush(tmp_bag, -heapq.heappop(jewel_heap)[1])

    if tmp_bag:
        answer -= heapq.heappop(tmp_bag)

    elif not jewel_heap:
        break

print(answer)
