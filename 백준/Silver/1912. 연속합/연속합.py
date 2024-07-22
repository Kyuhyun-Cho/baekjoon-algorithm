import sys

#sys.stdin = open("input.txt")

n = int(sys.stdin.readline().rstrip())
dp = list(map(int, sys.stdin.readline().split()))

for i in range(1, n):
    dp[i] = max(dp[i], dp[i-1]+dp[i])

print(max(dp))