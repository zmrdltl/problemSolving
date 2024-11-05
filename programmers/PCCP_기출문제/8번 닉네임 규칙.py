def solution(nickname):
    answer = ""
    for letter in nickname:
        if letter == "l":
            answer += "I"
        elif letter == "w":
            answer += "vv"
        elif letter == "W":
            answer += "VV"
        elif letter == "O":
            answer += "0"
        else:
            answer += letter
    if len(answer) < 3:
        answer += "o" * (4 - len(answer))
    if len(answer) > 8:
        answer = answer[:8]
    return answer