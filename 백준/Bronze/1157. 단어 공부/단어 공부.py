str = input()
str = str.lower()

dict = {}

for i in range(len(str)):
    if str[i] in dict:
        dict[str[i]] += 1
    else:
        dict[str[i]] = 1

arr = list(dict.values())

max = -99999

for i in range(len(arr)):
    if arr[i] > max:
        max = arr[i]

cnt = 0;

for i in range(len(arr)):
    if arr[i] == max:
        cnt += 1

if (cnt > 1):
    print('?')
else:
    for key, value in dict.items():
        if value == max:
            print(key.upper())
    