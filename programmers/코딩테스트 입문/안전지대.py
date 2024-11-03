def solution(board):
    dr = [-1, -1, -1, 0, 0, 0, 1, 1, 1]
    dc = [-1, 0, 1, -1, 0, 1, -1, 0, 1]
    answer = 0
    n = len(board)
    is_safe = [[1]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if board[i][j] == 0:
                continue
            for dir in range(9):
                nr = i + dr[dir]
                nc = j + dc[dir]
                if 0 > nr or nr >= n or 0 > nc or nc >= n:
                    continue
                is_safe[nr][nc] = 0
    for i in range(0, n):
        for j in range(0, n):
            if is_safe[i][j] == 1:
                answer += 1
    return answer