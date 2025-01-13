import sys
input = sys.stdin.readline
n = int(input())
a = sorted(list(map(int, input().split())))
def two_pointer():
    left = 0
    right = n - 1
    diff = 10**10
    while left < right:
        sum = a[left] + a[right]
        if abs(sum) < abs(diff):
            diff = sum
            num1, num2 = a[left], a[right]
        if sum <= 0:
            left += 1
        else:
            right -= 1
    if num1 > num2:
        return num2, num1
    return num1, num2

num1, num2 = two_pointer()
print(num1, num2)
