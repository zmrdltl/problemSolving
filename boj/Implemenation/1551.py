n,k = map(int,input().split())
l = input().split(',')

for i in range(k):
    newL = []

    for j in range(0, len(l) - 1):
        newL.append(int(l[j+1]) - int(l[j]))

    l = newL

for i in range(len(l)):
    print(l[i],end="")
    if(i!=len(l)-1) : print(',',end="")
