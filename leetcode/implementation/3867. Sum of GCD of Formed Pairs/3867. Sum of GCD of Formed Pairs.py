class Solution:
    def gcd(a:int, b:int) -> int:
        if b == 0:
            return a
        return gcd(b, a%b)

    def gcdSum(self, nums: list[int]) -> int:
        prefixGcd = []

        sum = 0

        current_max_num = nums[0]

        for num in nums:
            current_max_num = max(current_max_num, num)
            prefixGcd.append(gcd(num,current_max_num))
        prefixGcd.sort()

        prefix_gcd_len = len(prefixGcd)
        for i in range(prefix_gcd_len//2):
            sum += gcd(prefixGcd[i], prefixGcd[prefix_gcd_len-i-1])
        return sum
