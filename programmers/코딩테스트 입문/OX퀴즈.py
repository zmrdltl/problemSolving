def solution(quiz):
    answer = []
    for q in quiz:
        splited = q.split(' ')
        left_hand_side = int(splited[0])
        operator = splited[1]
        right_hand_side = int(splited[2])
        actual = int(splited[-1])
        expected = 0
        
        if operator == '+':
            expected = left_hand_side + right_hand_side
        else:
            expected = left_hand_side - right_hand_side
        if expected == actual:
            answer.append('O')
        else:
            answer.append('X')
    return answer