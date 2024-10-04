def solution(sizes):
    answer = 0
    
    for size in sizes:
        size.sort(reverse=True)
        
    width  = [size[0] for size in sizes]
    height = [size[1] for size in sizes]
    
    answer = max(width) * max(height)
    
    return answer