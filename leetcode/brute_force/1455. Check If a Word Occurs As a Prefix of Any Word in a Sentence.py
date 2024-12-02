class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        sentence = sentence.split(' ')
        for index, s in enumerate(sentence):
            if s.startswith(searchWord):
                return index+1
        return -1