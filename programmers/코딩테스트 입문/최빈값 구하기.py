def solution(array):
    dict = {}
    for num in array:
        dict[num] = dict.get(num,0) + 1
    
    max_freq = max(dict.values())
    max_freq_cnt = 0
    for key, value in dict.items():
        if max_freq == value:
            answer = key
            max_freq_cnt+=1
            
    if max_freq_cnt > 1:
        return -1
    return answer