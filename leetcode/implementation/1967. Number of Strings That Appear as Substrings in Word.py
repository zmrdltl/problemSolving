class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        answer = 0
        for p in patterns:
            if word.find(p) != -1:
                answer += 1
        return answer