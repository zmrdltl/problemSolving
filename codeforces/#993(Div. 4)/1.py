import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())
    ans = 0
    for i in range(1, 101):
        for j in range(1, 101):
            if i + j == n:
                ans += 1
    print(ans)
