def solution(myString):
    splited = myString.split('x')
    splited.sort()
    return [str for str in splited if str != ""]