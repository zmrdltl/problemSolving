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
    heapq.heappush(max_heap, (-10**9, start))  # 최대 힙: (현재까지 가능한 최대 중량, 현재 노드)
    max_weight = [0] * (n + 1)
    max_weight[start] = 10**9  # 시작 노드의 중량 제한은 무한대

    while max_heap:
        weight, node = heapq.heappop(max_heap)
        weight = -weight  # 최대 힙 사용을 위해 음수로 저장한 값을 되돌림

        if node == end:
            return weight  # 도착 지점에 도달하면 최대 중량 반환

        for next_node, limit in graph[node]:
            # 현재까지의 최소 중량 제한과 다음 다리의 중량 제한 중 작은 값을 사용
            next_weight = min(weight, limit)
            if next_weight > max_weight[next_node]:  # 더 큰 중량 제한으로 갱신 가능한 경우
                max_weight[next_node] = next_weight
                heapq.heappush(max_heap, (-next_weight, next_node))

    return 0  # 연결되지 않은 경우 (문제 조건상 항상 연결되므로 실행되지 않음)

print(dijkstra())
