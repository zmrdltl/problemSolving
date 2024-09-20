import itertools

class Solution(object):
    def countTriples(self, n):
        ans = 0
        for a in range(1, n+1):
            for b in range(1, n+1):
                c = (a**2 + b**2) ** 0.5
                if c.is_integer() and c <= n:
                    ans += 1
        return ans
