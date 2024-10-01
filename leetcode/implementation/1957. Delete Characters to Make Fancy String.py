class Solution:
    def makeFancyString(self, s: str) -> str:
        fancyStr = ""
        i = 0
        while i < len(s):
            cnt = 1
            while i+1 < len(s) and s[i] == s[i+1]:
                i += 1
                if cnt < 2:
                    cnt += 1
            fancyStr += s[i] * cnt
            i+=1

        return fancyStr