import sys
input = sys.stdin.readline

# 문자열 변환 함수
def convert_to_b(a):
    mapping = {'p': 'q', 'q': 'p', 'w': 'w'}  # 변환 규칙
    reversed_a = a[::-1]  # 문자열을 뒤집음
    return ''.join(mapping[char] for char in reversed_a)

# 입력 처리
t = int(input().strip())  # 테스트 케이스 개수
results = []

for _ in range(t):
    a = input().strip()  # 문자열 a
    b = convert_to_b(a)  # 변환된 문자열 b 계산
    results.append(b)

# 출력
sys.stdout.write('\n'.join(results) + '\n')
