import sys

# sys.stdin = open("input.txt")

n = int(sys.stdin.readline().rstrip())

time_table = [[] for _ in range(n)]

for i in range(n):
    start, end = map(int, sys.stdin.readline().split())
    time_table[i] = [start, end]

time_table = sorted(time_table, key=lambda x : (x[1], x[0]))

answer = 1

end_time = time_table[0][1]

for i in range(1, len(time_table)):
    if time_table[i][0] >= end_time:
        end_time = time_table[i][1]
        answer += 1

print(answer)
