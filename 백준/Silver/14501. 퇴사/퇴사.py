import sys

n = int(sys.stdin.readline().rstrip())

table = [ list(map(int, sys.stdin.readline().split())) for _ in range(n)]

dp = [0] * (n+1)

for i in range(n):
    for j in range(i+table[i][0], n+1):
        if dp[j] < dp[i] + table[i][1]:
            dp[j] = dp[i] + table[i][1]

print(dp[-1])