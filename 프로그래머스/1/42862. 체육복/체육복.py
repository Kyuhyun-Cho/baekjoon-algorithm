def solution(n, lost, reserve):
    answer = 0
    
    lst = [1] * (n+1)
    
    for i in lost:
        lst[i] -= 1
        
    for i in reserve:
        lst[i] += 1
        
    for i in range(1, len(lst)):
        left = i-1
        right = i+1
        
        if lst[i] == 2:
            if left > 0 and lst[left] == 0:
                lst[left] = 1
                lst[i] -= 1
                
            elif right < len(lst) and lst[right] == 0:
                lst[right] = 1
                lst[i] -= 1
    
    for i in range(1, len(lst)):
        if lst[i] != 0:
            answer += 1
    
    return answer