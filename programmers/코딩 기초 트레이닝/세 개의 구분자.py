def solution(myStr):
    answer = []
    delimeters = ['a', 'b', 'c']
    for delimeter in delimeters:
        myStr = myStr.replace(delimeter,'a')
    answer = myStr.split('a')
    answer = [str for str in answer if str != '']
    if not answer:
        answer.append('EMPTY')
    return answer