from collections import Counter

n = int(input())
books = []
for i in range(n):
	name = input()
	books.append(name)

counter = Counter(books).most_common()
counter.sort(key=lambda x : (-x[1], x[0]))

print(counter[0][0])
