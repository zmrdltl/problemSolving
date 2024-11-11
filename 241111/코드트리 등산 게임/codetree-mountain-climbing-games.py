import sys
input = sys.stdin.read

# 세그먼트 트리 생성 함수 (최대값 위치 찾기용)
def build_segment_tree(arr, tree, node, start, end):
    if start == end:
        tree[node] = start
    else:
        mid = (start + end) // 2
        build_segment_tree(arr, tree, node * 2, start, mid)
        build_segment_tree(arr, tree, node * 2 + 1, mid + 1, end)
        
        left = tree[node * 2]
        right = tree[node * 2 + 1]
        tree[node] = left if arr[left] >= arr[right] else right

# 세그먼트 트리로 최대값 위치 쿼리
def query_next_higher(tree, arr, node, start, end, pos, current_height):
    """
    현재 위치 pos 바로 오른쪽에서 current_height보다 높은 가장 가까운 위치 찾기
    """
    if end <= pos:
        return -1
    if start > pos and arr[tree[node]] <= current_height:
        return -1
    if start == end:
        return start if arr[start] > current_height else -1
    
    mid = (start + end) // 2
    left_result = query_next_higher(tree, arr, node * 2, start, mid, pos, current_height)
    if left_result != -1:
        return left_result
    return query_next_higher(tree, arr, node * 2 + 1, mid + 1, end, pos, current_height)

# 세그먼트 트리 생성 함수 (최소값 위치 찾기용)
def build_min_segment_tree(arr, tree, node, start, end):
    if start == end:
        tree[node] = start
    else:
        mid = (start + end) // 2
        build_min_segment_tree(arr, tree, node * 2, start, mid)
        build_min_segment_tree(arr, tree, node * 2 + 1, mid + 1, end)
        
        left = tree[node * 2]
        right = tree[node * 2 + 1]
        tree[node] = left if arr[left] <= arr[right] else right

# 세그먼트 트리 최솟값 위치 쿼리
def query_min(tree, arr, node, start, end, left, right):
    if right < start or end < left:
        return -1
    if left <= start and end <= right:
        return tree[node]
    
    mid = (start + end) // 2
    l_index = query_min(tree, arr, node * 2, start, mid, left, right)
    r_index = query_min(tree, arr, node * 2 + 1, mid + 1, end, left, right)
    
    if l_index == -1:
        return r_index
    if r_index == -1:
        return l_index
    return l_index if arr[l_index] <= arr[r_index] else r_index

data = input().splitlines()
success_score = 1000000
mountain = []
results = []
n = int(data[0])

for i in range(1, n + 1):
    operation = list(map(int, data[i].split()))
    op = operation[0]

    # 빅뱅 (초기화)
    if op == 100:
        mountain = operation[2:]
        m_len = len(mountain)
        max_seg_tree = [0] * (4 * m_len)
        min_seg_tree = [0] * (4 * m_len)
        build_segment_tree(mountain, max_seg_tree, 1, 0, m_len - 1)
        build_min_segment_tree(mountain, min_seg_tree, 1, 0, m_len - 1)

    # 우공이산 (산 추가)
    elif op == 200:
        new_mountain = operation[1]
        mountain.append(new_mountain)
        m_len = len(mountain)
        max_seg_tree = [0] * (4 * m_len)
        min_seg_tree = [0] * (4 * m_len)
        build_segment_tree(mountain, max_seg_tree, 1, 0, m_len - 1)
        build_min_segment_tree(mountain, min_seg_tree, 1, 0, m_len - 1)

    # 지진 (산 제거)
    elif op == 300:
        if mountain:
            mountain.pop()
            m_len = len(mountain)
            max_seg_tree = [0] * (4 * m_len)
            min_seg_tree = [0] * (4 * m_len)
            if m_len > 0:
                build_segment_tree(mountain, max_seg_tree, 1, 0, m_len - 1)
                build_min_segment_tree(mountain, min_seg_tree, 1, 0, m_len - 1)

    # 등산 시뮬레이션 (점수 계산)
    elif op == 400:
        m_index = operation[1] - 1  # 케이블카 위치 (0-based)
        
        # 최소 높이의 위치에서 등산 시작
        start = query_min(min_seg_tree, mountain, 1, 0, len(mountain) - 1, 0, len(mountain) - 1)
        max_score = 0
        current_score = 0
        pos = start
        current_height = mountain[pos]

        # 오른쪽으로 더 높은 산을 찾아 등산 진행
        while pos < len(mountain):
            # 케이블카 위치에 도달한 경우
            if pos == m_index:
                current_score += success_score
                # 케이블카를 타고 최저 높이 산으로 다시 이동하여 점수를 추가
                #print(pos)
                pos = query_min(min_seg_tree, mountain, 1, 0, len(mountain) - 1, 0, len(mountain) - 1)
                #print("케이블카 탐", pos, current_score)
                current_height = mountain[pos]
                m_index = -1
            
            # 현재 위치 바로 오른쪽에서 더 높은 산 찾기
            next_pos = query_next_higher(max_seg_tree, mountain, 1, 0, len(mountain) - 1, pos, current_height)
            if next_pos == -1:
                break
            current_score += success_score
            current_height = mountain[next_pos]
            #print("등반성공",pos, next_pos, current_score)
            pos = next_pos

        current_score += current_height
        max_score = max(max_score, current_score)
        results.append(max_score)

# 결과 출력
print("\n".join(map(str, results)))