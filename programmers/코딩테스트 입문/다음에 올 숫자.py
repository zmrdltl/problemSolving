def solution(common):
    answer = 0
    # 등차수열    
    if common[1] - common[0] == common[2] - common[1]:
        a = common[0]
        d = common[1] - common[0]
        return a + len(common) * d
    # 등비수열
    a = common[0]
    r = common[1] // common[0]
    return a*r**len(common)