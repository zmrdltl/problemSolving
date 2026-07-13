class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        ans = 0

        def check(r, c) -> bool:
            connected = 0
            for i in range(rows):
                if grid[i][c] == 1:
                    connected += 1
            for j in range(cols):
                if grid[r][j] == 1:
                    connected += 1
            return connected > 2

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 0:
                    continue
                if check(i,j):
                    ans += 1
        return ans
