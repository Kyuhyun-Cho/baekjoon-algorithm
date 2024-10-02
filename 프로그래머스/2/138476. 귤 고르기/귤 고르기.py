from collections import Counter

def solution(k, tangerine):
    answer = k
    
    tangerine = Counter(tangerine)
    tangerine = list(tangerine.values())
    tangerine.sort(reverse=True)

    total_cnt = 0
    
    for i in range(len(tangerine)):
        total_cnt += tangerine[i]
        if total_cnt >= k:
            return i+1

    return answer