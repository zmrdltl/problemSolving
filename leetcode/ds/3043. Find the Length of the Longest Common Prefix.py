class TrieNode:
    def __init__(self):
        self.children = {}
        self.isEndOfWord = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.isEndOfWord = True

    def findCommonPrefixLength(self, word):
        node = self.root
        prefixLen = 0
        for char in word:
            if char not in node.children:
                break
            node = node.children[char]
            prefixLen += 1
        return prefixLen
    
class Solution(object):
    def longestCommonPrefix(self, arr1, arr2):
        trie = Trie()
        for num in arr2:
            trie.insert(str(num))

        longestCommonLength = 0
        
        for num in arr1:
            numStr = str(num)
            commonPrefixLength = trie.findCommonPrefixLength(numStr)
            longestCommonLength = max(longestCommonLength, commonPrefixLength)

        return longestCommonLength
