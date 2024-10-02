class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:
        prefixes = ""
        for word in words:
            prefixes += word
            if s == prefixes:
                return True
        return False