class Solution(object):
    def subtractProductAndSum(self, n):
        num = list(map(int,str(n)))
        product = 1
        sum = 0
        for i in num:
            product *= i
            sum += i
        return product - sum