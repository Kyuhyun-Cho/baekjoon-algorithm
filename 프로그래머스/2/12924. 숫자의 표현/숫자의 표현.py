def solution(n):
    answer = 1
    
    if n == 1:
        return 1
    
    if n%2 == 0: 
        start = n//2
    else: 
        start = n//2+1
        
    for i in range(start, 0, -1):
        num = n
        for j in range(i, 0, -1):
            num -= j
            
            if num == 0:
                answer += 1
                
            elif num < 0:
                break
    
    
    return answer