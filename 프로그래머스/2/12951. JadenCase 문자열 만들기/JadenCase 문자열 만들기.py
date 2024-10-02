def solution(s):
    
    answer = []
    
    s = s.split(" ")

    for i in s:
        # print(i == "")
        if i == "":
            answer.append(i)
        elif i[0].isalpha():
            answer.append(i[0].upper() + i[1:len(i)].lower())
        else:
            answer.append(i[0] + i[1:len(i)].lower())
        
    answer = " ".join(answer)
        
    
    return answer