from collections import deque
class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        rowLength = len(isWater)
        colLength = len(isWater[0])

        def bfs():
            dr = [0,0,1,-1]
            dc = [1,-1,0,0]
            dq = deque()
            grid = [[0 for _ in range(colLength)] for _ in range(rowLength)]
            ck = [[0 for _ in range(colLength)] for _ in range(rowLength)]

            for i in range(rowLength):
                for j in range(colLength):
                    if isWater[i][j] == 1:
                        dq.append((i,j))
                        ck[i][j] = 1

            while dq:
                r, c = dq.popleft()
                for i in range(4):
                    nr = r + dr[i]
                    nc = c + dc[i]
                    if not 0 <= nr < rowLength or not 0 <= nc < colLength:
                        continue
                    if ck[nr][nc] == 1:
                        continue
                    grid[nr][nc] = grid[r][c] + 1
                    ck[nr][nc] = 1
                    dq.append((nr,nc))

            return grid

        return bfs()
