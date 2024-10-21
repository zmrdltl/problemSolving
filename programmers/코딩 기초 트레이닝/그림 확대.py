def solution(picture, k):
    answer = []
    for row in range(0,len(picture)):
        row_info = ''
        for char in picture[row]:
            row_info += char * k
        for i in range(0, k):
            answer.append(row_info)
    return answer