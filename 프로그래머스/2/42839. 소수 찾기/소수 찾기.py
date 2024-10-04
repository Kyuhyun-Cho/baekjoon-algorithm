import itertools

def check(num):
    if num == 0 or num == 1:
        return False
    
    if num == 2:
        return True
    
    for i in range(2, num):
        if num % i == 0:
            return False
        
    return True

def solution(numbers):
    answer = 0
    
    numbers = list(numbers)
    numbers_permutations = []
    
    for i in range(1, len(numbers)+1):
        numbers_permutations.append(list(itertools.permutations(numbers, i)))
        
    total_numbers = []        

    for numbers_list in numbers_permutations:
        for nums in numbers_list:
            total_numbers.append(int("".join(nums)))
    
    total_numbers = list(set(total_numbers))
    
    for num in total_numbers:
        if check(num) is True:
            answer += 1
    
    return answer