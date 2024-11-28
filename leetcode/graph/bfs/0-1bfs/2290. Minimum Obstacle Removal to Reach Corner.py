from collections import deque
class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        height = len(grid)
        width = len(grid[0])
        dr = [0,0,1,-1]
        dc = [1,-1,0,0]

        def bfs():
            dq = deque()
            check = [[0] * width for _ in range(height)]
            check[0][0] = 1
            dq.append((0,0,0))
            while dq:
                r, c, broke = dq.popleft()
                if r == height - 1 and c == width - 1:
                    return broke
                for i in range(4):
                    nr, nc = r + dr[i], c + dc[i]
                    if not (0<=nr<height and 0<=nc<width):
                        continue
                    if check[nr][nc] == 1:
                        continue
                    check[nr][nc] = 1
                    if grid[nr][nc] == 1:
                        dq.append((nr,nc,broke + 1))
                    elif grid[nr][nc] == 0:
                        dq.appendleft((nr,nc,broke))
            return -1
        
        return bfs()