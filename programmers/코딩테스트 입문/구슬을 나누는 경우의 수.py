def factorial(num):
    fac = 1
    for i in range(2, num + 1):
        fac *= i
    return fac

def solution(balls, share):
    return factorial(balls) // factorial(share)//factorial(balls - share)

# comb 사용
import math
def solution(balls, share):
    return math.comb(balls, share)