class Solution(object):
    def canBeTypedWords(self, text, brokenLetters):
        words = text.split(" ");
        inValidWordCount = 0
        for word in words:
            for w in word:
                if brokenLetters.find(w) != -1:
                    inValidWordCount += 1
                    break
        return len(words) - inValidWordCount