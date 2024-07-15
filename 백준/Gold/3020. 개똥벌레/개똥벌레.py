import sys
import math
from collections import Counter
from bisect import bisect_left

#sys.stdin = open("input.txt")

n, h = map(int, sys.stdin.readline().split())

bottom = []
top = []

for i in range(n):
    tmp = int(sys.stdin.readline().rstrip())
    if i % 2 == 0:
        bottom.append(tmp)
    else:
        top.append(tmp)

bottom.sort()
top.sort()

min_num = float("inf")
min_cnt = 0

for i in range(1, h+1):
    bottom_idx = bisect_left(bottom, i)
    top_idx = bisect_left(top, (h+1)-i)

    num = n - (bottom_idx + top_idx)

    if num < min_num:
        min_num = num
        min_cnt = 0

    if num == min_num:
        min_cnt += 1

print(min_num, min_cnt)
