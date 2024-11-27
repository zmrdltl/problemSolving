class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        in_degree_count = [0] * n
        for e in edges:
            in_degree_count[e[1]] += 1
        champion = -1
        champion_count = 0
        for node in range(n):
            if in_degree_count[node] == 0:
                champion_count += 1
                champion = node
            if champion_count > 1:
                return -1
        return champion