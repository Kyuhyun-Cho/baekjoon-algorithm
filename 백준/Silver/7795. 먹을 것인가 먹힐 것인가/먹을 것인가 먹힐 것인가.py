import sys

testCase = int(sys.stdin.readline())

for i in range(testCase):
    n, m = map(int, sys.stdin.readline().split())  

    a = list(map(int, sys.stdin.readline().split()))
    b = list(map(int, sys.stdin.readline().split()))

    a.sort(reverse=True)
    b.sort(reverse=True)

    i = 0
    j = 0

    answer = 0

    while (i < n and j < m):
        if (a[i] > b[j]):
            answer += m-j
            i += 1
        else:
            j += 1

    print(answer)