class Solution {
public:
    string interpret(string command) {
        string ans, piv; 
        for(auto c : command) {
            piv += c;
            if(piv == "G") {
                ans += piv;
                piv = "";
            } else if(piv == "()") {
                ans += 'o';
                piv = "";
            } else if(piv == "(al)") {
                ans += "al";
                piv ="";
            }
        }
        return ans;
    }
};