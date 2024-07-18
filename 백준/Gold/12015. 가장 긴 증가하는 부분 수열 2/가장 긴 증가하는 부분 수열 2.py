import sys
from bisect import bisect_left

#sys.stdin = open("input.txt")

n = int(sys.stdin.readline().rstrip())
lst = list(map(int, sys.stdin.readline().split()))

lis = [lst[0]]

for num in lst:
    if num > lis[-1]:
        lis.append(num)
    else:
        swap_idx = bisect_left(lis, num)
        lis[swap_idx] = num

print(len(lis))
