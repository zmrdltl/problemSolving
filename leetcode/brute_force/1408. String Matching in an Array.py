class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        length = len(words)
        answer = set()
        for i in range(length):
            for j in range(length):
                if i == j:
                    continue
                if words[j].find(words[i]) != -1:
                    answer.add(words[i])
        return list(answer)
