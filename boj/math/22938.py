from math import sqrt
import sys
input = sys.stdin.readline
info = list(map(int, input().split()))
info2 = list(map(int, input().split()))

dist = sqrt((info[0] - info2[0]) ** 2.0 + (info[1] - info2[1]) ** 2.0)
total_radian = info[2] + info2[2]
if dist >= total_radian: print("NO")
else: print("YES")