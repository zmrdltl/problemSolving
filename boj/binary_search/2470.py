import bisect
import sys
input = sys.stdin.readline

n = int(input())
a = sorted(list(map(int, input().split())))

def bisect_left(a, x):
    lo, hi = 0, len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if a[mid] < x:
            lo = mid + 1
        else:
            hi = mid
    return lo

def binary_search_closest(target, exclude_idx):
    idx = bisect.bisect_left(a, target)
    candidates = []

    if idx < len(a) and idx != exclude_idx:
        candidates.append(a[idx])
    if idx > 0 and idx - 1 != exclude_idx:
        candidates.append(a[idx - 1])

    return min(candidates, key=lambda num: abs(num - target)) if candidates else None

num1, num2, diff = 0, 0, 10**10

for i in range(n):
    x = -a[i]
    y = binary_search_closest(x, i)

    if y is None:
        continue

    if abs(a[i] + y) < abs(diff):
        num1, num2, diff = a[i], y, abs(a[i] + y)

print(*sorted([num1, num2]))
