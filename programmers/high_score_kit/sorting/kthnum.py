def solution(array, commands):
    answer = []
    arr2 = []
    for one_com in commands:
        arr2 = sorted(array[one_com[0]-1:one_com[1]])
        answer.append(arr2[one_com[2]-1])
    return answer
print(solution([1, 5, 2, 6, 3, 7, 4],[[2, 5, 3], [4, 4, 1], [1, 7, 3]]))