class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            chunks = [s[i:i+k] for i in range(0, len(s), k)]
            made = ""
            for chunk in chunks:
                sum = 0
                for d in chunk:
                    sum += int(d)
                made += str(sum)
            s = made
        return s
