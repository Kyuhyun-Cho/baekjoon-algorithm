import sys
import math

INF = float("inf")

#sys.stdin = open("input.txt")

n = int(sys.stdin.readline().rstrip())

lst = list(map(int, sys.stdin.readline().split()))

start = 0
end = n-1

min_val = INF
min_start = 0
min_end = n-1

while start < end:

    sum = lst[start]+lst[end]

    if abs(sum) <= abs(min_val):
        min_val = sum
        min_start = start
        min_end = end

    if sum == 0:
        break

    elif sum <= 0:
        start += 1

    else:
        end -= 1

print(lst[min_start], lst[min_end])