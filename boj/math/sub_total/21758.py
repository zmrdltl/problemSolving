import sys
input = sys.stdin.readline

def max_honey(n, honey):
    total_honey = sum(honey)
    accumulated_honey = [0] * n
    
    for i in range(n):
        accumulated_honey[i] = accumulated_honey[i-1] + honey[i]
        
    # 벌통 왼쪽 벌 두 마리 오른쪽        
    max_honey_case1 = 0
    for i in range(1, n-1):
        max_honey_case1 = max(max_honey_case1, accumulated_honey[n-1] - honey[i] - honey[-1] + accumulated_honey[i-1])
    
    # 벌통 오른쪽 벌 두 마리 왼쪽
    max_honey_case2 = 0
    for i in range(1, n-1):
        max_honey_case2 = max(max_honey_case2, accumulated_honey[n-1] - honey[i] - honey[0] + accumulated_honey[n-1] - accumulated_honey[i])
        
    max_honey_case3 = 0
    for i in range(1, n-1):
        left_sum = accumulated_honey[i] - honey[0]
        right_sum = accumulated_honey[-1] - accumulated_honey[i-1] - honey[-1]
        max_honey_case3 = max(max_honey_case3, left_sum + right_sum)
    return max(max_honey_case1, max_honey_case2, max_honey_case3)

n = int(input())
honey = list(map(int, input().split()))

print(max_honey(n, honey))