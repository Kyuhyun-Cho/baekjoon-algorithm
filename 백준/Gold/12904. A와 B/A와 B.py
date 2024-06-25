import sys

# sys.stdin = open("input.txt")

s = sys.stdin.readline().rstrip()
t = sys.stdin.readline().rstrip()

while len(t) != len(s):
    if t[-1] == 'A':
        t = t[:len(t)-1]
    elif t[-1] == 'B':
        t = t[:len(t)-1]
        t = t[::-1] # t.revese()

if t == s:
    print(1)
else:
    print(0)

