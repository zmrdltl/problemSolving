class Solution {
public:
    bool checkIfPangram(string sentence) {
        map <char, int> alphaMap;
        for(auto s : sentence) alphaMap[s]++;
        return alphaMap.size() == 26;
    }
};