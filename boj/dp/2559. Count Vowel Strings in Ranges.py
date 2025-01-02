class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        ans = []
        is_word_vowel = []

        def is_vowel_str(s):
            vowel_set = set(('a','e','i','o','u'))
            return s[0] in vowel_set and s[-1] in vowel_set

        for word in words:
            if is_vowel_str(word):
                is_word_vowel.append(1)
            else:
                is_word_vowel.append(0)

        vowel_str_sum = [0] * len(words)
        vowel_str_sum[0] = is_word_vowel[0]
        for i in range(1, len(words)):
            vowel_str_sum[i] = vowel_str_sum[i-1] + is_word_vowel[i]

        for query in queries:
            start_index = query[0]
            end_index = query[1]
            if start_index == 0:
                ans.append(vowel_str_sum[end_index])
            else:
                ans.append(vowel_str_sum[end_index] - vowel_str_sum[start_index-1])

        return ans
