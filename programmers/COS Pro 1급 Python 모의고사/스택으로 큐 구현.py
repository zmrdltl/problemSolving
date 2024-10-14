def func_a(stack):
    return stack.pop()

def func_b(stack1, stack2):
    while not func_c(stack1):
        item = func_a(stack1)
        stack2.append(item)

def func_c(stack):
    return (len(stack) == 0)

def solution(stack1, stack2):
    if func_c(stack2):
        func_b(stack1, stack2)
    answer = func_a(stack2)
    return answer

# 아래는 테스트케이스 출력을 해보기 위한 코드입니다.
stack1_1 = [1,2]
stack2_1 = [3,4]
ret1 = solution(stack1_1, stack2_1)

# [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret1, "입니다.")

stack1_2 = [1,2,3]
stack2_2 = []
ret2 = solution(stack1_2, stack2_2)

# [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret2, "입니다.")