class Solution:
    def minTimeToType(self, word: str) -> int:
        piv = 'a'
        move = 0
        for char in list(word):
            clockwise_move = ord(char) - ord(piv)
            if clockwise_move < 0:
                clockwise_move += 26
            counter_clockwise_move = ord(piv) - ord(char)
            if counter_clockwise_move < 0:
                counter_clockwise_move += 26
            move += min(clockwise_move,counter_clockwise_move)
            piv = char
            move+=1
        return move
