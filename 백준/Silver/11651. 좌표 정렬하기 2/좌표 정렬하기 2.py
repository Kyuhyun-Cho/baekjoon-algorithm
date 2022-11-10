import sys

n = int(input())

board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

board.sort(key=lambda x:(x[1],x[0]))

for i in range(n):
	print(board[i][0], end=' ')
	print(board[i][1])