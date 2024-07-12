import sys

#sys.stdin = open("input.txt")

n = int(sys.stdin.readline().rstrip())
lst = sorted(list(map(int, sys.stdin.readline().split())))

answer = 0

for i in range(n):
    target= lst[i]

    start = 0
    end = n-1
    # print(f"[{target}]")
    while start < end:

        if start == i:
            start += 1

        if end == i:
            end -= 1

        if start == end:
            break

        # print(start, end)

        mid = (start + end)//2
        sum = lst[start] + lst[end]

        if sum == target:
            answer += 1
            # print("Check!")
            break

        elif sum < target:
            start += 1

        else:
            end -= 1        

    # print()    
print(answer)