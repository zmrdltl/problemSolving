
def solution(n):
    answer = 1
    fac = 1
        
    for num in range(1, 11):
        fac *= num
        if fac <= n:
            answer = num
    return answer