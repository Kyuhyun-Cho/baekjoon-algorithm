import itertools

def solution(word):
    answer = 0
    
    lst = ['A', 'E', 'I', 'O', 'U'] * 5

    word_list = set()
    
    for i in range(1, 6):
        tmp = (list(itertools.permutations(lst, i)))
        for j in range(len(tmp)):
            word_list.add("".join(tmp[j]))
            
    word_list = sorted(list(word_list))
    
    answer = word_list.index(word)+1
    
    return answer