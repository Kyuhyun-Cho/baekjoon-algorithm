from fractions import Fraction

nm = input().split()
n = int(nm[0])
m = int(nm[1])

if (n < m*2):
    m = n - m

answer = 1
for i in range(n, n-m, -1):
    answer *= i
for i in range(1, m+1):
    answer = Fraction(answer, i)

print(int(answer))