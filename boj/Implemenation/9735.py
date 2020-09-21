import sys

r = sys.stdin.readline

def getFactor(num): #약수구하기
    L = []
    for i in range(1,int(num**0.5)+1):
        if num%i == 0:
            L.append(i)
            if num//i != i:
                L.append(num//i)
    return L

def ARC(d,a): #성질 이용해 정수해 빠르게 구하기
    dlist = getFactor(d)
    alist = getFactor(a)
    for i in dlist:
        for j in alist:
            N = i//j
            if N == 0: #zero division 방지
                continue
            for l in [N,-N]:
                judge = 0
                for k in sik: #sik = [A,B,C,D]
                    judge = (judge * l) + k #빠르게 다항식 합 구하기(안빠름)
                if judge == 0:
                    return l 

for _ in range(int(r())):
    sik = list(map(int, r().split()))
    if sik[3] == 0: #상수항이 없다면 0인 근이 적어도 하나 존재
        ans1 = 0
    else:
        ans1 = ARC(abs(sik[3]),abs(sik[0]))
    A = sik[0]
    B = A*ans1+sik[1]
    C = B*ans1+sik[2]
    D = B*B-4*A*C
    answer = []
    answer.append(ans1)
    if D == 0:
        ans2 = -(B/(2*A))
        if ans1 != ans2:
            answer.append(ans2)
    elif D > 0:
        ans2 = (-B+(D)**0.5)/(2*A)
        ans3 = (-B-(D)**0.5)/(2*A)
        if ans1 == ans2:
            answer.append(ans3)
        elif ans1 == ans3:
            answer.append(ans2)
        else:
            answer.append(ans2)
            answer.append(ans3)
    answer.sort()
    print(" ".join(map(str,answer)))