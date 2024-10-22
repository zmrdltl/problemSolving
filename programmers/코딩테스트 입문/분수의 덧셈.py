def gcd(num1, num2):
    if num1 % num2 == 0:
        return num2
    return gcd(num2, num1 % num2)

def solution(numer1, denom1, numer2, denom2):
    denom_gcd = gcd(denom1, denom2)
    denom_lcm = denom1 * denom2 // denom_gcd
    numer1 *= denom_lcm // denom1
    numer2 *= denom_lcm // denom2
    numer3 = (numer1 + numer2)
    denom3 = denom_lcm
    result_gcd = gcd(numer3, denom3)        
        
    return [numer3 // result_gcd, denom3 // result_gcd]