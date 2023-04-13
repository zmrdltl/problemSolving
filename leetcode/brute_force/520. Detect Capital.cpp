class Solution {
public:
    bool isAllCapitals(string word){
        for(auto w : word) {
            if('A' > w || w > 'Z') return false;
        }
        return true;
    }
    bool isAllNotCapitals(string word){
        for(auto w : word) {
            if('a' > w || w > 'z') return false;
        }
        return true;
    }
    bool isOnlyFistCapital(string word) {
        if('A' > word[0] || word[0] > 'Z') return false;
        for(int i = 1; i < word.size(); i++) {
            if('a' > word[i] || word[i] > 'z') return false;
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        return isAllCapitals(word) || isAllNotCapitals(word) || isOnlyFistCapital(word);
    }
};