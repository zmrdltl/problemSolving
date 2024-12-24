from collections import deque, defaultdict
class Solution:
    def minimumDiameterAfterMerge(self, edges1: List[List[int]], edges2: List[List[int]]) -> int:
        def build_graph(edges):
            graph = defaultdict(list)
            for edge in edges:
                graph[edge[0]].append(edge[1])
                graph[edge[1]].append(edge[0])
            return graph

        def bfs_diameter(graph):
            def bfs(start):
                dq = deque([(start,0)])
                visited = {}
                visited[start] = True
                furthest_node, max_dist = start, 0
                while dq:
                    node, dist = dq.popleft()
                    for next in graph[node]:
                        if visited.get(next):
                            continue
                        visited[next] = True
                        if dist + 1 > max_dist:
                            furthest_node, max_dist = next, dist + 1
                        dq.append((next, dist + 1))
                return furthest_node, max_dist

            furthest_node, _ = bfs(0)
            _, diameter = bfs(furthest_node)

            return diameter

        graph1 = build_graph(edges1)
        graph2 = build_graph(edges2)
        diameter1 = bfs_diameter(graph1)
        diameter2 = bfs_diameter(graph2)

        return max((diameter1), (diameter2), (diameter1 + 1) // 2 + (diameter2 + 1) // 2 + 1)
