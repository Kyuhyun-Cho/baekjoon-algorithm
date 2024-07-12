import sys

#sys.stdin = open("input.txt")

n, c = map(int, sys.stdin.readline().split())

house = []

for _ in range(n):
    x = int(sys.stdin.readline().rstrip())
    house.append(x)

house.sort()

start = 1
end = house[-1] - house[0]
answer = 0

while start <= end:
    mid = (start + end) // 2
    current = house[0]
    cnt = 1

    for i in range(1, len(house)):
        if current + mid <= house[i]:
            cnt += 1
            current = house[i]

    if c <= cnt:
        answer = mid
        start = mid + 1

    else:
        end = mid - 1

print(answer)
    