import sys
n = int(sys.stdin.readline().rstrip())

listNum = list(map(int, sys.stdin.readline().rstrip().split()))

maxNum = -9000001

minNum  = 9000001

for i in range(n):
    if maxNum < listNum[i]:
        maxNum = listNum[i]

    if minNum > listNum[i]:
        minNum = listNum[i]

print(minNum, maxNum)