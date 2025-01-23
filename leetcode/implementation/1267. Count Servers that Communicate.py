from collections import deque

class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        can_communicate = 0
        ck = [[0 for _ in range(cols)] for _ in range(rows)]

        def count_row_server(start_row:int) -> int:
            count = 0
            for c in range(cols):
                if grid[start_row][c] == 1:
                    count += 1
            return count

        def count_col_server(start_col:int) -> int:
            count = 0
            for r in range(rows):
                if grid[r][start_col] == 1:
                    count += 1
            return count

        def check_rows(start_row:int):
            count_unchecked = 0
            for r in range(rows):
                if ck[r][j] == 0 and grid[r][j] == 1:
                    ck[r][j] = 1
                    count_unchecked += 1
            return count_unchecked

        def check_cols(start_col:int):
            count_unchecked = 0
            for c in range(cols):
                if ck[i][c] == 0 and grid[i][c] == 1:
                    ck[i][c] = 1
                    count_unchecked += 1
            return count_unchecked

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 0:
                    continue

                row_count = count_row_server(i)
                col_count = count_col_server(j)

                if row_count + col_count - 1 > 1:
                    can_communicate += check_rows(i)
                    can_communicate += check_cols(j)

        return can_communicate
