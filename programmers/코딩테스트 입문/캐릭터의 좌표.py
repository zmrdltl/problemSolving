dx = [-1,1,0,0]
dy = [0,0,1,-1]

def next_coord(pos, dir):
    return [pos[0] + dx[dir], pos[1] + dy[dir]]

def is_valid(coord, width_limit, height_limit):
    return -width_limit <= coord[0] and coord[0] <= width_limit and -height_limit <= coord[1] and coord[1] <= height_limit

def solution(keyinput, board):
    answer = [0,0]
    width_limit = board[0] // 2
    height_limit = board[1] // 2
    for input in keyinput:
        coord = []
        if input == 'left':
            coord = next_coord(answer, 0)
            print(coord)
        elif input == 'right':
            coord = next_coord(answer, 1)
        elif input == 'up':
            coord = next_coord(answer, 2)
        else:
            coord = next_coord(answer, 3)
        if is_valid(coord, width_limit, height_limit):
                answer = coord
    return answer