import sys
a = []
for i in range(3):
    a.append(int(sys.stdin.readline().strip()))
print((a[1] - a[2]) // a[0])