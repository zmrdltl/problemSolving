class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedString;
        int pivot = 0;
        int maxSize = max(word1.size(), word2.size());
        while(pivot < maxSize) {
            if(pivot < word1.size())
                mergedString += word1[pivot];
            if(pivot < word2.size())
                mergedString += word2[pivot];
            pivot++;
        }
        return mergedString;
    }
};