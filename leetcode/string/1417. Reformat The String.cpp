class Solution {
public:
    string reformedString(stack<char> a, stack<char> b){
        string s;

        while(a.size() && b.size()) {
            s += a.top();
            a.pop();
            s += b.top();
            b.pop();
        }
        if(a.size()) {
            s += a.top();
            a.pop();
        }
        return s;
    }

    string reformat(string s) {
        stack <char> digits, alphas;
        for(auto c : s) {
            if('a' <= c && c <= 'z') alphas.push(c);
            else digits.push(c);
        }
        if(abs((int)digits.size() - (int)alphas.size()) >= 2) return "";

        if(digits.size() >= alphas.size()) {
            return reformedString(digits, alphas);
        }

        return reformedString(alphas, digits);
    }
};