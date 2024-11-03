
def solution(dots):
    x_max = max(dots[i][0] for i in range(4))
    x_min = min(dots[i][0] for i in range(4))
    y_max = max(dots[i][1] for i in range(4))
    y_min = min(dots[i][1] for i in range(4))
    return (x_max - x_min) * (y_max - y_min)