def solution(a, b, c):
    arr = [a,b,c]
    arr.sort()
    if arr[0] != arr[1] and arr[1] != arr[2]:
        return  a + b + c
    elif arr[0] == arr[1] and arr[1] == arr[2]:
        return (a + b + c) * (a**2 + b**2 + c**2) * (a**3 + b**3 + c**3)
    return (a + b + c) * (a**2 + b**2 + c**2)
    