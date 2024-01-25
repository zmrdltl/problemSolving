class Solution {
public:
    string freqAlphabets(string s) {
        string decryptedString;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1' || s[i] == '2') {
                if (i + 2 < s.size() && s[i+2] == '#') {
                    int num = stoi(s.substr(i,2));
                    decryptedString += num - 1 + 'a';
                    i += 2;
                } else {
                    decryptedString += s[i] - '0' - 1 + 'a';
                }
            }
            else {
                decryptedString += s[i] - '0' - 1 + 'a';
            }
        }
        return decryptedString;
    }
};