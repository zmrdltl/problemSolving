def solution(a, b, c, d):
    dices = [a,b,c,d]
    dices.sort()
    
    frequency_dict = {}
    for number in dices:
        frequency_dict[number] = frequency_dict.get(number, 0) + 1
    category_size = len(frequency_dict)
    if category_size == 1:
        return 1111*dices[0]
    if category_size == 2:
        p, q = 0,0
        for key, value in frequency_dict.items():
            if value == 3:
                p = key
            elif value == 1:
                q = key
            else:
                p = dices[0]
                q = dices[2]
                return (p+q) * abs(p-q)
        return (10*p+q)**2
    if category_size == 3:
        keys = [key for key, value in frequency_dict.items() if value != 2]
        q, r = keys[0], keys[1]
        return q * r
                                
    return dices[0]
