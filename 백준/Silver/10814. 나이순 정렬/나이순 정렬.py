n = int(input())

arr = [[0 for i in range(3)] for j in range(n)]

for i in range(n):
    age_name = input().split()

    arr[i][0] = i
    arr[i][1] = int(age_name[0])
    arr[i][2] = age_name[1]

arr.sort(key=lambda x: (x[1], x[0]))

for i in range(n):
    print(arr[i][1], arr[i][2])