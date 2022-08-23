import sys
input = sys.stdin.readline
a, b = map(int, input().split())

sum = 0
piv = 0

for i in range (1, a + 1):
  sum += i

piv = sum

for i in range(a+1, b + 1):
  piv += i
  sum *= piv

print(sum%14579)