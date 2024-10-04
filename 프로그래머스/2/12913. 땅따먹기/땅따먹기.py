def solution(land):
    answer = 0
    
    for i in range(len(land)-1):
        for j in range(4):
            
            if j == 0:
                max_num = max(land[i][1], land[i][2], land[i][3])
            elif j == 1:
                max_num = max(land[i][0], land[i][2], land[i][3])
            elif j == 2:
                max_num = max(land[i][1], land[i][0], land[i][3])
            elif j == 3:
                max_num = max(land[i][1], land[i][2], land[i][0])
            
            land[i+1][j] += max_num
    
    answer = max(land[-1])
        
    return answer