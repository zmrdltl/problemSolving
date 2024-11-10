def solution(park, routes):
    h, w = len(park), len(park[0])
    start_h, start_w = 0,0
    for i in range(0, h):
        for j in range(0, w):
            if park[i][j] == 'S':
                start_h, start_w = i, j
    
    dh = {'E': 0, 'W': 0, 'S': 1, 'N': -1}
    dw = {'E': 1, 'W': -1, 'S': 0, 'N': 0}
    
    for r in routes:
        route = r.split(' ')
        direction, move = route[0], int(route[1])
        is_valid = True
        ch, cw = start_h, start_w
        for i in range(0, move):
            nh = ch + dh[direction]
            nw = cw + dw[direction]
            if 0 > nh or nh >= h or 0 > nw or nw >= w or park[nh][nw] == 'X':
                is_valid = False
                break
            ch, cw = nh, nw
        if is_valid:
            start_h, start_w = ch, cw
    return [start_h, start_w]