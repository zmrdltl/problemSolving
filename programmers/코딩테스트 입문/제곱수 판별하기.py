def solution(n):
    for i in range(1, 1001):
        if i**2 == n:
            return 1
    return 2