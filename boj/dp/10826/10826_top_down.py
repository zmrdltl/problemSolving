import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
n = int(input())
f = [0 for i in range(10001)]

def fibo(n):
    if(f[n] != 0): return f[n]
    if(n == 0): return 0
    if(n == 1): return 1
    f[n] = fibo(n-1) + fibo(n-2)
    return f[n]
    
print(fibo(n))
