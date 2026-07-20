import copy
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        row_len = len(grid)
        col_len = len(grid[0])
        shiftedGrid = [[0] * col_len for _ in range(row_len)]
        for _ in range(k):
            for i in range(row_len):
                for j in range(col_len):
                    shiftedGrid[i][j] = grid[i][(j - 1) % col_len]
                shiftedGrid[i][0] = grid[(i-1) % row_len][col_len-1]
            shiftedGrid[0][0] = grid[row_len-1][col_len-1]
            grid = copy.deepcopy(shiftedGrid)
        return grid
