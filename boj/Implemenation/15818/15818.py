import sys
input = sys.stdin.readline

n, m = map(int, input().split())
nums = list(map(int, input().split()))
ans = 1
for i in range(0,n):
  ans *= nums[i]
print(ans%m)