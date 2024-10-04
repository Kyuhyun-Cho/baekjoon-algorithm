import itertools

def solution(k, dungeons):
    answer = 0
    
    dungeons = list(itertools.permutations(dungeons, len(dungeons)))
    
    for phase in dungeons:
        tmp_k = k
        tmp_answer = 0
        for info in phase:
            min_k   = info[0]
            minus_k = info[1]            
            
            if tmp_k >= min_k:
                tmp_k -= minus_k
                tmp_answer += 1
        
        if tmp_answer > answer:
            answer = tmp_answer
    
    return answer