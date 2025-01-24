class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        state = [0 for _ in range(len(graph))]
        def dfs(node: int) -> bool:
            if state[node] > 0:
                return state[node] == 2
            state[node] = 1
            for neighbor in graph[node]:
                if not dfs(neighbor):
                    return False
            state[node] = 2
            return True

        return [i for i in range(len(graph)) if dfs(i)]
