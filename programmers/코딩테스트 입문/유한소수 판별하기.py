def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

def solution(a, b):
    gcd_val = gcd(a,b)
    a = a // gcd_val
    b = b // gcd_val
    while b % 5 == 0:
        b /= 5
    while b % 2 == 0:
        b /= 2
    if b <= 1:
        return 1
    return 2