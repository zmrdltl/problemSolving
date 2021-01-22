import sys

testCase = 3

while testCase:
    n = int(sys.stdin.readline())
    s = 0
    for i in range(0,n):
        a = int(sys.stdin.readline())
        s += a
    if s > 0:
        print('+')
    elif s < 0:
        print('-')
    else:
        print('0')
    testCase -= 1
