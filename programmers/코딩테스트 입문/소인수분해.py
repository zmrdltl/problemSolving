import math
def prime(limit):
    check = [False] * (limit + 1)
    primes = []
    for i in range(2, int(math.sqrt(limit)) + 1):
        if check[i] == True:
            continue
        for j in range(i+i, limit + 1, i):
            check[j] = True
    for i in range(2, limit + 1):
         if not check[i]:
            primes.append(i)
    return primes

def solution(n):
    answer = []
    primes = prime(n)
    for p in primes:
        if n % p == 0:
            answer.append(p)
    return answer