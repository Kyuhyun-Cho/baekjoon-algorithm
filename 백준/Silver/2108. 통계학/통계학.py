import sys
from collections import Counter

n = int(sys.stdin.readline())
arr = []
for _ in range(n):
	arr.append(int(sys.stdin.readline()))

mean = round(sum(arr) / len(arr))
print(mean)

arr.sort()
mid = arr[int(n/2)]
print(mid)

cnt = Counter(arr).most_common()
cnt_arr = []
cnt_arr.append(cnt[0][0])

for i in range(1, len(cnt)):
	if (cnt[i][1] == cnt[0][1]):
		cnt_arr.append(cnt[i][0])

if (len(cnt_arr) == 1):
	print(cnt_arr[0])
else:
	cnt_arr.sort()
	print(cnt_arr[1])

range = arr[-1] - arr[0]
print(range)
