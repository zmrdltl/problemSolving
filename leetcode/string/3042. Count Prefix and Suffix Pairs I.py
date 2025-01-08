class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        length = len(words)
        ans = 0
        def isPrefixAndSuffix(word1: str, word2: str) -> bool:
            return word2.startswith(word1) and word2.endswith(word1)

        for i in range(length):
            for j in range(i+1, length):
                if isPrefixAndSuffix(words[i], words[j]):
                    ans += 1
        return ans
