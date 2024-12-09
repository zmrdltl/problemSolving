from collections import deque

n, m = map(int, input().split())
graph = {i: [] for i in range(1, n + 1)}

for _ in range(m):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))
    graph[v].append((u, w))

start, end = map(int, input().split())

def can_transport(weight):
    ck = [False] * (n+1)
    ck[start] = True
    dq = deque([start])
    while dq:
        node = dq.popleft()
        if node == end:
            return True
        for next_node, limit in graph[node]:
            if ck[next_node] or limit < weight:
                continue
            ck[next_node] = True
            dq.append(next_node)
    return False

low, high = 1, 10**9
result = low
while low <= high:
    mid = (low + high) // 2
    if can_transport(mid):
        result = mid
        low = mid + 1
    else:
        high = mid - 1

print(result)
