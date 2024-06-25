import sys

#sys.stdin = open("input.txt")

t = int(sys.stdin.readline().rstrip())

while (t > 0):
    t -= 1
    n = int(sys.stdin.readline().rstrip())

    ranks = []

    for i in range(n):
        rank_1, rank_2 = map(int, sys.stdin.readline().split())
        ranks.append([rank_1, rank_2])

    ranks = sorted(ranks, key=lambda x:x[0])

    min_rank = ranks[0][1]

    answer = n

    for i in range(1, n):
        current_rank = ranks[i][1]
        if (current_rank < min_rank):
            min_rank = current_rank
        else:
            answer -= 1

    print(answer)