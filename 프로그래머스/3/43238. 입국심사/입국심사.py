def solution(n, times):
    answer = []
    
    left = 0
    right = max(times) * n
    mid = (left+right)//2

    while left <= right:
        mid = (left+right)//2
        
        people = 0
        
        for time in times:
            people += mid//time
            
            if people >= n:
                break
        
        if people >= n :
            answer.append(mid)
            right = mid - 1
        else:
            left = mid + 1
            
    answer = min(answer)
    
    return answer