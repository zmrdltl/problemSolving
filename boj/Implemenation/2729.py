import sys
input = sys.stdin.readline
n = int(input())

for i in range(n):
    a, b = map(str,input().split())
    c = int(a,2) + int(b,2)
    print(bin(c)[2:])
