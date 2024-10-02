def solution(s):
    answer = 0
    
    stack = []
    
    for i in s:
        if not stack:
            stack.append(i)
        else:
            
            j = stack.pop()
            
            if i != j:
                stack.append(j)
                stack.append(i)
    
    if not stack:
        answer = 1
    
    return answer