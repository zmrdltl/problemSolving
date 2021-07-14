a,b = map(int,input().split())
isBad = 0
badNum = 0
prime = []

for i in range(1,b - 1):
    if(a % i == 0):
        isBad = 1
        badNum = i;
        break

if(isBad): print("BAD", badNum)
else: print("GOOD")