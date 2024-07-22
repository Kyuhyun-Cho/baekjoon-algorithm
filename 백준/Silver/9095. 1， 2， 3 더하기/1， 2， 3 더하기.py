import sys

#sys.stdin = open("input.txt")

t = int(sys.stdin.readline().rstrip())

for testcase in range(t):
    dp = [0] * 11
    dp[1] = 1
    dp[2] = 2
    dp[3] = 4

    n = int(sys.stdin.readline().rstrip())

    for i in range(4, n+1):
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
    
    print(dp[n])