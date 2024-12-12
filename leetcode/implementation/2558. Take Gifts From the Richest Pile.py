class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        for _ in range(k):
            max_pile_idx = gifts.index(max(gifts))
            gifts[max_pile_idx] = int(sqrt(gifts[max_pile_idx]))
        return sum(gifts)