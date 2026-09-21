class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        # 양 옆 제하고 남은것 곱했을때 k로 나눈 나머지가 x
        ans = [0]*k
        cur = {}

        for n in nums:
            next_cur = {}

            for rem, cnt in cur.items():
                new_rem = rem*n % k
                next_cur[new_rem] = next_cur.get(new_rem,0) + cnt

            new_rem = n % k
            next_cur[new_rem] = next_cur.get(new_rem,0) + 1

            for rem, cnt in next_cur.items():
                ans[rem] += cnt

            cur = next_cur

        return ans
