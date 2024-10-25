def solution(angle):
    if 0 < angle and angle < 90:
        return 1
    elif angle == 90:
        return 2
    elif 90 < angle and angle < 180:
        return 3
    return 4
