import sys

# sys.stdin = open("input.txt")

n = int(sys.stdin.readline().rstrip())

dp = [99999 for _ in range(5001)]

dp[0] = -1
dp[1] = -1
dp[2] = -1
dp[3] = 1
dp[4] = -1
dp[5] = 1

for i in range(6, n+1):
    for j in range(i-1, i//2 - 1, -1):
        if (dp[j] != -1) and (dp[i-j] != -1):
            dp[i] = min(dp[j] + dp[i-j], dp[i])

    if dp[i] == 99999:
        dp[i] = -1
            
# print(dp)

print(dp[n])
