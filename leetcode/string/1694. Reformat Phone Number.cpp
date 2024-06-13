class Solution {
public:
    string getFilteredNum(string number) {
        string num;
        for(auto n : number) {
            if (n != '-' && n != ' ') num += n;
        }
        return num;
    }

    string getReformatNum(string filteredNum) {
        string reformatNum;
        for(int i = 0; i < filteredNum.size(); i+=3) {
            if (filteredNum.size() - i == 4) {
                reformatNum += filteredNum.substr(i, 2) + '-';
                i--;
            } else if(i + 3 < filteredNum.size()) {
                reformatNum += filteredNum.substr(i, 3) + '-';
            } else {
                reformatNum += filteredNum.substr(i);
            }
        }
        return reformatNum;
    }

    string reformatNumber(string number) {
        string filteredNum = getFilteredNum(number);
        return getReformatNum(filteredNum);
    }
};