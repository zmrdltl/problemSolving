class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        i, j, diff = 0, 0, 0
        while i < len(str1) and j < len(str2):
            c1, c2 = str1[i], str2[j]
            if c1 == c2 or chr((ord(c1) + 1 - 97) % 26 + 97) == c2:
                i+=1
                j+=1
                continue
            i+=1
        return j == len(str2)