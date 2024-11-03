def solution(A, B):
    answer = -1
    cnt = 0
    A_copy = A
    # 오른쪽으로 밀기
    for i in range(0, len(A_copy)+1):
        if A_copy == B:
            answer = cnt
            break
        A_copy = A_copy[-1] + A_copy[0:len(A_copy)-1]
        cnt += 1
    cnt = 0
    # 왼쪽으로 밀기
    for i in range(0, len(A_copy)+1):
        if A_copy == B:
            if cnt != 0:
                answer = min(answer, cnt)
            break;
        A_copy = A_copy[1:] + A_copy[0]
    return answer