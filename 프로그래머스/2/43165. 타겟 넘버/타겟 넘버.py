from collections import deque

def solution(numbers, target):
    answer = 0
    
    queue = deque()
    queue.append((numbers[0], 0))
    queue.append((numbers[0]*-1, 0))

    length = len(numbers)
    
    while queue:
        num, i = queue.popleft()
    
        i += 1
            
        if i < len(numbers):
            queue.append((num+numbers[i], i))
            queue.append((num-numbers[i], i))
        else:
            if num == target:
                answer += 1
            
    return answer