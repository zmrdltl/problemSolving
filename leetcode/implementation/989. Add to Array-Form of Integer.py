import sys

sys.set_int_max_str_digits(15000)

class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        num = int(''.join(map(str,num)))
        return list(map(int, str(k+num)))