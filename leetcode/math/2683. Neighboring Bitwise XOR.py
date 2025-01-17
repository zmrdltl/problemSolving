class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        xor_sums = 0
        for num in derived:
            xor_sums ^= num
        return xor_sums == 0
