import sys

n = int(input())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

board.sort(key=lambda x : (x[0],x[1]))

for i in range(n):
	for j in range(2):
		print(board[i][j], end = " ")
	print()
	