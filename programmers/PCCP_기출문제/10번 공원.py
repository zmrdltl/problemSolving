def solution(mats, park):
    answer = -1
    for r in range(len(park)):
        for c in range(len(park[0])):
            if park[r][c] != "-1":
                continue
            for mat in mats:
                is_valid = True
                for i in range(r, r + mat):
                    for j in range(c, c + mat):
                        if i >= len(park) or j >= len(park[0]):
                            is_valid = False
                            continue
                        if park[i][j] != "-1":
                            is_valid = False
                if is_valid == True:
                    answer = max(answer, mat)
    return answer