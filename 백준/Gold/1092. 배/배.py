import sys
import heapq

#sys.stdin = open("input.txt")

n = int(sys.stdin.readline().rstrip())
crane_list = list(map(int, sys.stdin.readline().split()))

m = int(sys.stdin.readline().rstrip())
box_list = list(map(int, sys.stdin.readline().split()))

crane_list.sort(reverse=True)
box_list.sort(reverse=True)

answer = 0

if box_list[0] > crane_list[0]:
    answer = -1
else:
    while box_list:
        for crane in crane_list:
            if box_list and crane < box_list[-1]:
                continue
            
            for box in box_list:
                if crane >= box:
                    box_list.remove(box)
                    break
        answer += 1

print(answer)


