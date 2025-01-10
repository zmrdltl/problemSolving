from collections import defaultdict
class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        answer = []
        words2_map = defaultdict(int)
        for word in words2:
            words2_char_map = defaultdict(int)
            for char in word:
                words2_char_map[char] += 1
            for char, freq in words2_char_map.items():
                words2_map[char] = max(words2_map[char], freq)
        for word in words1:
            words1_map = defaultdict(int)
            is_valid = True
            for char in word:
                words1_map[char] += 1
            for char, freq in words2_map.items():
                if words1_map[char] < freq:
                    is_valid = False
                    break
            if is_valid:
                answer.append(word)
        return answer
