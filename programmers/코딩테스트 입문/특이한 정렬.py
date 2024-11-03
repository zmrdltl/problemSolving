def solution(numlist, n):
    numlist = sorted(numlist, key = lambda x : (abs(n-x), -x))
    return numlist