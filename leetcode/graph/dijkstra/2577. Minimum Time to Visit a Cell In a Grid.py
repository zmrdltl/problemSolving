from heapq import heappop, heappush

class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        height = len(grid)
        width = len(grid[0])
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1

        def dijkstra():
            dr = [0,0,1,-1]
            dc = [1,-1,0,0]
            pq = []
            checked = [[0x3f3f3f3f]*width for _ in range(height)]
            checked[0][0] = 1
            heappush(pq, (0,0,0))
            while pq:
                time, r, c = heappop(pq)
                if r == height - 1 and c == width - 1:
                    return time
                if time > checked[r][c]:
                    continue
                
                for i in range(4):
                    nr, nc = r + dr[i], c + dc[i]
                    if not (0<=nr<height and 0<=nc<width):
                        continue
                    if (grid[nr][nc] - time) % 2 == 0:
                        wait_time = max(0, grid[nr][nc] - time)
                    else:
                        wait_time = max(0, grid[nr][nc] - time - 1)
                    next_time = time + 1 + wait_time
                    if checked[nr][nc] > next_time:
                        checked[nr][nc] = next_time
                        heappush(pq, (next_time, nr, nc))
            return -1
        return dijkstra()