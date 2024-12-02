import sys
from collections import deque
input = sys.stdin.readline
n,k = map(int, input().split())
dq = deque()
dq.append((n,0))
check = [0]*100001
check[n] = 1
def bfs():
    while dq:
        pos, time = dq.popleft()
        if pos == k:
            return time
        if pos-1 >= 0 and check[pos-1] == 0:
            check[pos-1] = 1
            dq.append((pos-1, time+1))
        if pos+1 <= 100000 and check[pos+1] == 0:
            check[pos+1] = 1
            dq.append((pos+1, time+1))
        if pos*2 <= 100000 and check[pos*2] == 0:
            check[pos*2] = 1
            dq.append((pos*2, time+1))
    return -1
print(bfs())