class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int moves = 0; moves < s.size(); moves++) {
            string shiftedString = s;
            for(int move = 0; move < moves; move++) {
                shiftedString = shiftedString.substr(1) + shiftedString[0];
            }
            if(shiftedString == goal) return true;
        }
        return false;
    }
};