def solution(rank, attendance):
    participants = {}
    for i in range(0, len(rank)):
        if attendance[i]:
            participants[i] = rank[i]
    sorted_participants = sorted(participants.items(), key = lambda x: x[1])

    a = sorted_participants[0][0]
    b = sorted_participants[1][0]
    c = sorted_participants[2][0]
    return 10000 * a + 100 * b + c