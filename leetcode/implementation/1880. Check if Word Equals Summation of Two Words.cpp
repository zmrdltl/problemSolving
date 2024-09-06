class Solution {
public:
    int getNum(string word) {
        string numStr;
        for(auto w : word) {
            numStr += to_string(w -'a');
        }
        return stoi(numStr);
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int firstNum = getNum(firstWord);
        int secondNum = getNum(secondWord);
        int targetNum = getNum(targetWord);
        return firstNum+secondNum == targetNum;
    }
};