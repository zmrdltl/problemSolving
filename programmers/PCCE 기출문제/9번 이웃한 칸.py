from queue import Queue
dh = [0,0,1,-1]
dw = [1,-1,0,0]

def solution(board, h, w):
    n = len(board)
    m = len(board[0])
    answer = 0
    for i in range(0, 4):
        nh = h + dh[i]
        nw = w + dw[i]
        if 0 > nh or nh >= n or 0 > nw or nw >= m:
            continue
        if board[nh][nw] != board[h][w]:
            continue
        answer+=1
    return answer