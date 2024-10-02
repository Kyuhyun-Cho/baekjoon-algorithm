def solution(citations):
    answer = 0
    
    for i in range(len(citations), 0, -1):
        cnt = 0
        for num in citations:
            if i <= num:
                cnt += 1
                
        if cnt >= i:
            answer = i
            break
    
    return answer