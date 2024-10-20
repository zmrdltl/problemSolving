def solution(arr):
    x = []
    for n in arr:
        a = [n]*n
        x.extend(a)
    return x