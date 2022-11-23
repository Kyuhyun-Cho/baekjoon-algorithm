str = input()

alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
cnt = [-1 ,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 ,-1 ,-1, -1, -1, -1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1]

for i in range(len(str)):
    for j in range(len(alphabet)):
        if str[i] == alphabet[j] and cnt[j] == -1:
            cnt[j] = i

print(*cnt)