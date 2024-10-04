import heapq

def check(scoville, k):
    for s in scoville:
        if s < k:
            return False
    return True

def solution(scoville, K):
    answer = 0
    
    heapq.heapify(scoville)
    
    while check(scoville, K) is False:
        if len(scoville) == 1:
            return -1
        
        first = heapq.heappop(scoville)
        second = heapq.heappop(scoville)
        
        new = first + second*2
        
        heapq.heappush(scoville, new)
        
        answer += 1
    
    
    return answer