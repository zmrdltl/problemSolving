def solution(numbers, direction):
    answer = []
    if direction == 'right':
        answer.append(numbers[-1])
        answer.extend(numbers[:-1])
    else:
        answer = numbers[1:]
        answer.append(numbers[0])
    return answer