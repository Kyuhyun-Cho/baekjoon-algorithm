num = input()
num_list = list(map(int, num))

num_list.sort(reverse=True)

zero_check = False
sum = 0
for i in range(len(num_list)):
    sum += num_list[i]
    if num_list[i] == 0:
        zero_check = True

if (zero_check and sum % 3 == 0):
    for i in range(len(num_list)):
        print(num_list[i], end='')
else:
    print(-1)