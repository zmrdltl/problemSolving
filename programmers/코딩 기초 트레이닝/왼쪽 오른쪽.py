def findIndex(str_list, char):
    try:
        return str_list.index(char)
    except ValueError:
        return -1

def solution(str_list):
    lIndex = findIndex(str_list, 'l')
    rIndex = findIndex(str_list, 'r')
    
    if lIndex != -1 and (rIndex == -1 or lIndex < rIndex):
        return str_list[:lIndex]
    
    if rIndex != -1 and (lIndex == -1 or rIndex < lIndex):
        return str_list[rIndex+1:]
    
    return []
