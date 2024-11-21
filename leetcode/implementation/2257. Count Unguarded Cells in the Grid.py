from collections import deque
class Solution:
    
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        grid = [[0]*n for _ in range(m)]
        checked = [[0]*n for _ in range(m)]
        dr = [0,0,1,-1]
        dc = [1,-1,0,0]
        dq = deque()
        answer = 0
        for g in guards:
            dq.append((g[0], g[1]))
            checked[g[0]][g[1]] = 1
            grid[g[0]][g[1]] = 'G'
        for w in walls:
            grid[w[0]][w[1]] = 'W'
            checked[w[0]][w[1]] = 1

        while dq:
            r, c = dq.popleft()
            for i in range(4):
                current_row = r
                current_col = c
                while True:
                    nr = current_row + dr[i]
                    nc = current_col + dc[i]
                    if not (0<=nr<m and 0<=nc<n):
                        break
                    if grid[nr][nc] == 'W' or grid[nr][nc] == 'G':
                        break
                    checked[nr][nc] = 1
                    current_row = nr
                    current_col = nc
                    
        for i in range(m):
            for j in range(n):
                if checked[i][j] == 0:
                    answer += 1
        return answer
