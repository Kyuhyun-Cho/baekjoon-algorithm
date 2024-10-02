from collections import Counter

def solution(topping):
    answer = 0
    
    a = Counter(topping)
    b = dict()
    
    for t in topping:
        
        if len(a) == len(b):
            answer += 1

        if t not in b:
            b[t] = 1
            a[t] -= 1
        
        else:
            b[t] += 1
            a[t] -= 1
        
        if a[t] == 0:
            a.pop(t)
    
    return answer