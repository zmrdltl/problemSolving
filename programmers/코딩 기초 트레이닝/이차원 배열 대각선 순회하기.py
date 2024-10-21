def solution(board, k):
    answer = 0
    for r in range(0, len(board)):
        for c in range(0, len(board[0])):
            if r + c <= k:
                answer += board[r][c]
    return answer