class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        colLength = len(grid[0])
        prefix_row0 = [0] * colLength
        prefix_row1 = [0] * colLength

        prefix_row0[0] = grid[0][0]
        prefix_row1[0] = grid[1][0]

        for i in range(1, colLength):
            prefix_row0[i] = prefix_row0[i-1] + grid[0][i]
            prefix_row1[i] = prefix_row1[i-1] + grid[1][i]

        total_row0_point = prefix_row0[-1]

        result = float('inf')

        for i in range(colLength):
            points_above = total_row0_point - prefix_row0[i]
            points_below = prefix_row1[i-1] if i > 0 else 0

            second_robot_max_point = max(points_above, points_below)
            result = min(result, second_robot_max_point)

        return result
