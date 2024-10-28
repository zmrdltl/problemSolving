def solution(my_string):
    answer = []
    for char in my_string:
        if char.isdigit():
            answer.append(int(char))
    answer.sort()
    return answer