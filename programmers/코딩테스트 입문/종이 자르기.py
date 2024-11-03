def solution(M, N):
    # 더 긴 변부터 잘라야 최소로 자를 수 있음
    # 먼저 잘랐을 때 max(M, N)개의 조각이 생기고 이를 작은 변 - 1만큼 곱해야함
    return (max(M, N) - 1) + (min(M,N) -1)* max(M, N)