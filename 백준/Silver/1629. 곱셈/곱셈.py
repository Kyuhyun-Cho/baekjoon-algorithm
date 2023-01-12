import sys

def mul(a, b, c):
	if b == 1: 
		return a % c
	elif b % 2 == 0:
		return (mul(a, b//2, c)**2) % c
	else:
		return ((mul(a, b//2, c)**2)*a) % c

a, b, c = map(int, sys.stdin.readline().split())
print(mul(a, b, c))