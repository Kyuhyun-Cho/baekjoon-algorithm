def solution(number, k):
    answer = [] # stack
    
    for num in number:
        # print(answer)
        if len(answer) == 0:
            answer.append(num)
            continue
        
        if k > 0:
            while answer[-1] < num:
                answer.pop()
                k -= 1
                
                if k == 0:
                    break
                
                if len(answer) == 0:
                    # answer.append(num)
                    break
            answer.append(num)
            
        else:
            answer.append(num)
                
    # print(answer)
    answer = ''.join(answer[:len(answer)-k])
    # print(answer)
    return answer