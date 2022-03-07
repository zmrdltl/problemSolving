import sys
input = sys.stdin.readline
n = int(input())
num = int(n)
ans = 0
for num in range(1, n+1):
    sum = 0
    stringN = str(num)
    lenN = len(stringN)
    for j in range(lenN):
        sum += int(stringN[j])
    if(num % sum == 0): ans+=1
print(ans)