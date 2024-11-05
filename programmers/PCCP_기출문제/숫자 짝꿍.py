from collections import Counter

def solution(X, Y):
    common_count = Counter(X) & Counter(Y)
    common_num = []
    
    for d in range(9, -1, -1):
        digit_str = str(d)
        if digit_str in common_count:
            common_num.append(digit_str * common_count[digit_str])
            
    if not common_num:
        return "-1"
        
    common_num = ''.join(common_num)
    
    if common_num == "0" * len(common_num):
        return "0"
    
    return common_num
