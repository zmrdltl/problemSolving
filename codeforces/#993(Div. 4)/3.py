import sys
input = sys.stdin.readline

# 입력 처리
t = int(input().strip())  # 테스트 케이스 개수
results = []

for _ in range(t):
    m, a, b, c = map(int, input().strip().split())

    # 1행 자리 채우기
    seated_row1 = min(a, m)  # 1행에 a가 앉을 수 있는 최대 자리
    remaining_seats_row1 = max(0, m - seated_row1)  # 1행에 남은 자리
    seated_row1 += min(c, remaining_seats_row1)  # c로 1행 남은 자리 채우기
    remaining_c = c - min(c, remaining_seats_row1)  # 사용 후 남은 c

    # 2행 자리 채우기
    seated_row2 = min(b, m)  # 2행에 b가 앉을 수 있는 최대 자리
    remaining_seats_row2 = max(0, m - seated_row2)  # 2행에 남은 자리
    seated_row2 += min(remaining_c, remaining_seats_row2)  # 남은 c로 2행 자리 채우기

    # 최대 원숭이 수 저장
    results.append(seated_row1 + seated_row2)

# 출력
sys.stdout.write('\n'.join(map(str, results)) + '\n')
