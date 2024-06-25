import sys
import heapq

# sys.stdin = open("input.txt")

n = int(sys.stdin.readline().rstrip())

card_heap = []

for i in range(n):
    card = int(sys.stdin.readline().rstrip())
    heapq.heappush(card_heap, card)

answer = 0

while len(card_heap) > 1:
    first_card = heapq.heappop(card_heap)
    second_card = heapq.heappop(card_heap)
    
    new_card = first_card + second_card

    answer += new_card

    heapq.heappush(card_heap, new_card)

print(answer)