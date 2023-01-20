def solution(n):
    answer = 0
    string = ''
    while(n > 0):
        if (n % 3 == 0): 
            string = string + '0'
        elif (n % 3 == 1): 
            string = string + '1'
        else: 
            string = string + '2'
        n = n // 3
    for i in range(len(string)):
        answer = answer + int(string[len(string) - i - 1]) * 3**i
    
    return answer