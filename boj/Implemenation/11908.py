import sys
input = sys.stdin.readline
k, n = map(int, input().split())
tmp = (k*n)//(n-1)
if((k*n) % (n-1)): tmp += 1
if(n == 1): print(-1)
else: print(tmp)