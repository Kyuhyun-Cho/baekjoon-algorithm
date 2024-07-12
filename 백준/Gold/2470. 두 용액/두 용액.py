import sys
import math

INF = float("inf")

#sys.stdin = open("input.txt")

n  = int(sys.stdin.readline().rstrip())

lst = sorted(list(map(int, sys.stdin.readline().split())))

# print(lst)  

left = 0
right = n-1

min_val = INF
min_left = 0
min_right = n-1

while left < right:
    mid_val = (lst[left] + lst[right])

    # print(left, right, mid_val)
    
    if abs(mid_val) < abs(min_val):
        min_val = mid_val
        min_left = left
        min_right = right

    if mid_val == 0:
        min_left = left
        min_right = right
        break

    elif mid_val < 0:
        left = left + 1
    
    elif 0 < mid_val:
        right = right - 1
    
    # print("->", min_left, min_right, min_val)
    # print()

print(lst[min_left], lst[min_right])