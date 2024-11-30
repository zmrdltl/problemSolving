from collections import deque

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        dq = deque()
        dq.append(source)
        check = [0]*n
        check[source] = 1
        edges_map = {i:[] for i in range(n)}
        for e in edges:
            edges_map[e[0]].append(e[1])
            edges_map[e[1]].append(e[0])

        while dq:
            node = dq.popleft()
            if node == destination:
                return True
            for e in edges_map[node]:
                if check[e] == 1:
                    continue
                check[e] = 1
                dq.append(e)

        return False