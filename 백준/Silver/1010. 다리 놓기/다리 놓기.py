from fractions import Fraction
T = int(input())

for t in range(T):
	nm = input().split()
	n = int(nm[0])
	m = int(nm[1])

	if (m < n*2):
	    n = m - n

	answer = 1
	for i in range(m, m-n, -1):
	    answer *= i
	for i in range(1, n+1):
	    answer = Fraction(answer, i)
	
	print(int(answer))
	