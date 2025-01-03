# from collections import deque

# n, m = map(int, input().split())
# graph = {i: [] for i in range(1, n + 1)}

# for _ in range(m):
#     u, v, w = map(int, input().split())
#     graph[u].append((v, w))
#     graph[v].append((u, w))

# start, end = map(int, input().split())

# def can_transport(weight):
#     ck = [False] * (n+1)
#     ck[start] = True
#     dq = deque([start])
#     while dq:
#         node = dq.popleft()
#         if node == end:
#             return True
#         for next_node, limit in graph[node]:
#             if ck[next_node] or limit < weight:
#                 continue
#             ck[next_node] = True
#             dq.append(next_node)
#     return False

# low, high = 1, 10**9
# result = low
# while low <= high:
#     mid = (low + high) // 2
#     if can_transport(mid):
#         result = mid
#         low = mid + 1
#     else:
#         high = mid - 1

# print(result)
import heapq

n, m = map(int, input().split())
graph = {i: [] for i in range(1, n + 1)}

for _ in range(m):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))
    graph[v].append((u, w))

start, end = map(int, input().split())

# 다익스트라 알고리즘
def dijkstra():
    max_heap = []
    heapq.heappush(max_heap, (-10**9, start))
    max_weight = [0] * (n+1)
    max_weight[start] = 10**9
    while max_heap:
        weight, node = heapq.heappop(max_heap)
        weight = -weight
        if node == end:
            return weight
        for next_node, limit in graph[node]:
            next_weight = min(weight, limit)
            if max_weight[next_node] < next_weight:
                max_weight[next_node] = next_weight
                heapq.heappush(max_heap, (-next_weight, next_node))
    return 0

print(dijkstra())
