import sys

input = sys.stdin.readline

def count_valid_pairs(k, l1, r1, l2, r2):
    count = 0
    power = 1  # \( k^n \), 초기 값은 \( k^0 = 1 \)

    while power <= r2:
        # 가능한 x의 범위를 계산
        x_min = max(l1, (l2 + power - 1) // power)  # l2 / \( k^n \) 올림
        x_max = min(r1, r2 // power)  # r2 / \( k^n \) 내림

        # x_min <= x_max이면 유효한 \( x \)가 존재
        if x_min <= x_max:
            count += x_max - x_min + 1

        # \( k^n \) 값 갱신
        if power > r2 // k:
            break
        power *= k
        

    return count

# 입력 처리
t = int(input().strip())
results = []

for _ in range(t):
    k, l1, r1, l2, r2 = map(int, input().strip().split())
    results.append(count_valid_pairs(k, l1, r1, l2, r2))

# 결과 출력
sys.stdout.write('\n'.join(map(str, results)) + '\n')
