class Solution {
public:
    map <char, bool> jewelsMap;
    
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        jewelsMap.clear();
        for(auto j : jewels) jewelsMap[j] = true;
        for(auto s : stones) if(jewelsMap[s]) ans++;
        return ans;
    }
};