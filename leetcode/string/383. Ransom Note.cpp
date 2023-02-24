class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map <char, int> magazineMap;
        for(auto m : magazine) {
            magazineMap[m]++;
        }
        for(auto r : ransomNote) {
            if(!magazineMap[r]) return false;
            magazineMap[r]--;
        }
        return true;
    }
};