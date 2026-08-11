class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        mem = {}
        sum = [piles[0]]
        pile_len = len(piles)
        for i in range(1, pile_len):
            sum.append(sum[i-1] + piles[i])
        # dp(piv, M): piv위치부터 현 플레이어가 1~2M 개의 pile을 선택할 수 있을 때 최종적으로 얻는 최대 돌 개수
        def dp(piv: int, m: int):
            if mem.get((piv,m)):
                return mem[(piv,m)]
            best = 0
            remaining_candidate = 0
            if piv == 0:
                remaining_candidate = sum[-1]
            else:
                remaining_candidate = sum[-1] - sum[piv-1]
            for x in range(1, min(2*m, pile_len - piv)+1):
                current = dp(piv + x, max(m,x))
                opposite = remaining_candidate - current
                best = max(best, opposite)
            mem[(piv,m)] = best
            return mem[(piv,m)]

        return dp(0,1)
