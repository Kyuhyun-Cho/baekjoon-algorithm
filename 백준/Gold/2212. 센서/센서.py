import sys

# sys.stdin = open("input.txt")

n = int(sys.stdin.readline().rstrip())
k = int(sys.stdin.readline().rstrip())

sensor_list = list(map(int, sys.stdin.readline().split()))

sensor_list = list(set(sensor_list))

sensor_list.sort()

diff_list = [0]

for i in range(len(sensor_list)-1):
    diff_list.append(sensor_list[i+1] - sensor_list[i])

diff_list.sort()

answer = 0

for i in range(len(diff_list)-(k-1)):
    answer += diff_list[i]

if n == 2:
    answer = diff_list[-1] 

print(answer)
