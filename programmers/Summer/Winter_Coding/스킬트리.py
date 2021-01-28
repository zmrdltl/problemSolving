def solution(skill, skill_trees):
    answer = 0
    for skill_tree in skill_trees:
        arr = [skill_tree.find(char) for char in skill]
        for idx, ele in enumerate(arr[1:]):
            if ele == -1:
                continue
                
            # ele != -1
            if arr[idx] == -1 or arr[idx] > ele:
                break
                
        else:
            answer += 1
            
    return answer