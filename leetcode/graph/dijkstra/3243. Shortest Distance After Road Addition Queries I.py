from heapq import heappop, heappush
class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        def dijkstra(edges, end):
            pq = []
            distances = [0x3f3f3f3f] * n
            distances[0] = 0
            heappush(pq, (0,0))
            while pq:
                distance, node = heappop(pq)
                if node == end:
                    return distance
                if distance > distances[node]:
                    continue
                
                for next_node in edges[node]:
                    if distance + 1 < distances[next_node]:
                        distances[next_node] = distance + 1
                        heappush(pq, (distances[next_node], next_node))
            return -1

        edges = {i: [i+1] for i in range(n)}
        distances = []
        for q in queries:
            edges[q[0]].append(q[1])
            distances.append(dijkstra(edges, n-1))
        return distances
        