from collections import deque
import sys
input = sys.stdin.readline

# 입력 처리
n, m, k = map(int, input().strip().split())
map_input = [list(map(int, input().strip())) for _ in range(n)]

def bfs():
    dr = [0,0,1,-1]
    dc = [1,-1,0,0]
    queue = deque([(0,0,0)])
    check = [[[1000001] * (k+1) for _ in range(m)] for _ in range(n)]
    check[0][0][0] = 1
    while queue:
        r, c, break_cnt = queue.popleft()
        
        if r == n - 1 and c == m - 1:
            return check[r][c][break_cnt]
        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]
            if not (0 <= nr < n and 0 <= nc < m):
                continue
            #벽을 부수지 않고 이동가능한 경우
            if map_input[nr][nc] == 0 and check[nr][nc][break_cnt] > check[r][c][break_cnt] + 1:
                check[nr][nc][break_cnt] = check[r][c][break_cnt] + 1
                queue.append((nr,nc,break_cnt))
            if map_input[nr][nc] == 1 and break_cnt < k and check[nr][nc][break_cnt + 1] > check[r][c][break_cnt] + 1:
                check[nr][nc][break_cnt + 1] = check[r][c][break_cnt] + 1
                queue.append((nr,nc,break_cnt+1))
    return -1

print(bfs())