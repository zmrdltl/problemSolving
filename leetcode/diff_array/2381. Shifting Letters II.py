class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        length = len(s)
        diff = [0] * (length+1)
        diff_sums = [0]*length
        for shift in shifts:
            start_index = shift[0]
            end_index = shift[1]
            direction = shift[2]

            if direction == 0:
                diff[start_index] -= 1
                diff[end_index+1] += 1
            else:
                diff[start_index] += 1
                diff[end_index+1] -= 1

        for i in range(0, length):
            diff_sums[i] = diff_sums[i-1] + diff[i]

        ans = ''
        for i in range(length):
            changed = chr((ord(s[i]) - ord('a') + diff_sums[i])%26 + ord('a'))
            ans += changed
        return ans
