from collections import deque
def solution(maps):
    rows, cols = len(maps), len(maps[0])
    answer = 0
    dr, dc = [0,0,1,-1], [1,-1,0,0]
    dq = deque()
    ck = [[-1]*cols for _ in range(rows)]
    dq.append((0,0))
    ck[0][0] = 1

    while dq:
        r, c = dq.popleft()
        for i in range(0,4):
            nr,nc= r + dr[i], c + dc[i]
            if nr < 0 or nr >= rows or nc < 0 or nc >= cols:
                continue
            if maps[nr][nc] == 0:
                continue
            if ck[nr][nc] != -1:
                continue
            ck[nr][nc] = ck[r][c] + 1
            dq.append((nr,nc))
    return ck[rows-1][cols-1]
