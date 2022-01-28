a, b, n = map(int,input().split())
ans = 0
for i in range(n+1):
    ans = a//b
    a = a%b * 10
print(ans)