answer = []
for i in range(1,6):
    agent = input()
    if(agent.count("FBI")):
        answer.append(i)

for i in range(0,len(answer)):
    print(answer[i],end=' ')

if(len(answer)==0):
    print("HE GOT AWAY!")
