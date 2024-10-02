def solution(want, number, discount):
    answer = 0
    
    my_dict = dict(zip(want, number))

    for i in range(len(discount)):
        tmp_my_dict = my_dict.copy()
        
        for j in range(i, i+10):
            if j >= len(discount):
                continue
            
            if discount[j] in tmp_my_dict.keys():
                tmp_my_dict[discount[j]] -= 1
                
                if tmp_my_dict[discount[j]] < 0:
                    tmp_my_dict[discount[j]] = 0
        
        if sum(list(tmp_my_dict.values())) == 0:
            answer += 1
    
    return answer