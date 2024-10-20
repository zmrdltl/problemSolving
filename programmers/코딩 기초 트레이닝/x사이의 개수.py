def solution(myString):
    answer = []
    splited = myString.split('x')
    for str in splited:
        answer.append(len(str))
    return answer