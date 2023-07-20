class Solution {
public:
    vector <string> split(string paragraph) {
        vector <string> result;
        string word;
        for(auto c : paragraph) {
            if(c == '!' || c == '?' || c == '\'' || c == ',' || c == ';' || c == '.' || c == ' ') {
                result.push_back(word);
                word = "";
                continue;
            }
            word += tolower(c);
        }
        result.push_back(word);
        return result;
    }

    string mostCommonWord(string paragraph, vector<string>& banned) {
        map <string, int> frequencyMap;
        map <string, int> bannedMap;
        for(auto b : banned) {
            bannedMap[b] = 1;
        }
        vector <string> words = split(paragraph);
        for(string &word: words) {
            if(bannedMap[word] || word == "") continue;
            frequencyMap[word]++;
        }
        auto maxElement = max_element(frequencyMap.begin(), frequencyMap.end(),
        [] (const auto& a, const auto& b) {
            return a.second < b.second;
        });
        return maxElement->first;
    }
};