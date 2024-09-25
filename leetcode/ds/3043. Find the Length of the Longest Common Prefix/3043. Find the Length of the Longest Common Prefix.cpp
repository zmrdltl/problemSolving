
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    int findCommonPrefixLength(const string& word) {
        TrieNode* node = root;
        int prefixLen = 0;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                break;
            }
            node = node->children[ch];
            prefixLen++;
        }
        return prefixLen;
    }
};

class Solution {
public:
    int longestCommonPrefix(const vector<int>& arr1, const vector<int>& arr2) {
        Trie trie;
        for (int num : arr2) {
            trie.insert(to_string(num));
        }

        int longestCommonLength = 0;

        for (int num : arr1) {
            string numStr = to_string(num);
            int commonPrefixLength = trie.findCommonPrefixLength(numStr);
            longestCommonLength = max(longestCommonLength, commonPrefixLength);
        }

        return longestCommonLength;
    }
};