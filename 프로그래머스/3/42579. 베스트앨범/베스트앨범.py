def solution(genres, plays):
    answer = []
    
    dictionary = dict()
    
    for i in range(len(genres)):
        if genres[i] not in dictionary:
            dictionary[genres[i]] = [(plays[i], i)]
        else:
            dictionary[genres[i]].append((plays[i],i))
    
    for values in dictionary.values():
        values.sort(key = lambda x: (x[0], -x[1]), reverse=True)
        
        total_play = 0
        for play in values:
            total_play += play[0]
        
        values.append(total_play)
    
    dictionary = dict(sorted(dictionary.items(), key=lambda x: x[1][-1], reverse=True))
    
    # print(dictionary)
    for item in dictionary.items():

        if len(item[1]) - 1 >= 2:
            answer.append(item[1][0][1])
            answer.append(item[1][1][1])
        else:
            answer.append(item[1][0][1])
    
    return answer