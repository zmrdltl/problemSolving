class Solution {
public:
    vector <string> split (string input, char delimeter){
        stringstream ss(input);
        string tmp;
        vector <string> res;
        while(getline(ss, tmp, delimeter)) {
            if (!tmp.empty())  // 빈 문자열은 결과에 포함시키지 않음
                res.push_back(tmp);
        }
        return res;
    }

    string reorderSpaces(string text) {
        int totalSpace = count(text.begin(), text.end(), ' ');
        vector <string> splited = split(text, ' ');
        int wordCount = splited.size();

        int spaceBetweenWords = wordCount > 1 ? totalSpace / (wordCount - 1) : 0;
        int extraSpace = wordCount > 1 ? totalSpace % (wordCount - 1) : totalSpace;

        string ans;
        for(int i = 0; i < splited.size(); i++) {
            ans += splited[i];
            if(i != splited.size() - 1) {
                ans.append(spaceBetweenWords, ' ');
            }
        }
        ans.append(extraSpace, ' ');
        return ans;
    }
};