class Solution:


    def minimizeXor(self, num1: int, num2: int) -> int:
        bin_num1 = bin(num1)
        bin_num2 = bin(num2)
        target_bit_count = bin_num2.count('1')
        x = ''
        bit_count = 0

        for char in bin_num1:
            if char == '1':
                bit_count += 1

            if bit_count > target_bit_count:
                x += '0'
            else:
                x += char

        ans = 0
        if len(x) < target_bit_count:
            while bit_count < target_bit_count:
                x += '1'
                bit_count+=1
        else:
            x = list(x)
            for i in range(len(x)-1,-1,-1):
                if x[i] == '1':
                    continue
                if bit_count < target_bit_count:
                    x[i] = '1'
                    bit_count += 1
        for char in x:
            offset = 1 if char == '1' else 0
            ans = ans * 2 + offset
        return ans
