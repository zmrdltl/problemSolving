from pickletools import long1
import sys
input = sys.stdin.readline
n = int(input())

def binary_search():
  s = 1
  e = n
  while s <= e:
    mid = (s + e) // 2
    if(mid ** 2 <= n): s = mid + 1
    else: e = mid - 1
  return e

print(binary_search())