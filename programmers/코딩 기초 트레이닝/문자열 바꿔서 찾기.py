def solution(myString, pat):
    answer = 0
    toggledString = ''
    for char in myString:
        if char == 'A':
            toggledString += 'B'
        else:
            toggledString += 'A'
    if toggledString.find(pat) != -1:
        answer = 1
    return answer