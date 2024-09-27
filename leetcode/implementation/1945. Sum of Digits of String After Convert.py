class Solution:
    def getTransformed(self, k: int) -> int:
        sum = 0
        while k > 0:
            sum += int(k % 10)
            k = k // 10
        return sum

    def getConvert(self, s: str) -> int:
        convertedStr = ""
        for char in s:
            convertedStr += str(ord(char) - 96)
        return  int(convertedStr)

    def getLucky(self, s: str, k: int) -> int:
        convertedNum = self.getConvert(s)
        for i in range(0,k):
            convertedNum = self.getTransformed(convertedNum)
        return convertedNum