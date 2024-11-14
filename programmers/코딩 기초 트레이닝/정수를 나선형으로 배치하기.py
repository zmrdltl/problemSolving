def solution(n):
    #우,하,좌,상
    dr = [0,1,0,-1]
    dc = [1,0,-1,0]
    answer = [[0] * n for _ in range(n)]
    val = 1
    r, c = 0, 0
    direction = 0
    
    for i in range(0, n*n):
        answer[r][c] = val
        val += 1
        
        nr = r + dr[direction]
        nc = c + dc[direction]
        
        if 0 > nr or nr >= n or 0 > nc or nc >= n or answer[nr][nc]!=0:
            direction = (direction + 1) % 4
            nr = r + dr[direction]
            nc = c + dc[direction]
        
        r, c = nr, nc
        
    return answer