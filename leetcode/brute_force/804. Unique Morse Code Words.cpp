class Solution {
public:
    vector <string> morse = {
        ".-",
        "-...",
        "-.-.",
        "-..",
        ".",
        "..-.",
        "--.",
        "....",
        "..",
        ".---",
        "-.-",
        ".-..",
        "--",
        "-.",
        "---",
        ".--.",
        "--.-",
        ".-.",
        "...",
        "-",
        "..-",
        "...-",
        ".--",
        "-..-",
        "-.--",
        "--.."
    };
    
    int uniqueMorseRepresentations(vector<string>& words) {
        map<string, int> transformMap;
        for(auto word : words) {
            string transformedWord;
            for(auto w : word) {
                transformedWord += morse[w - 'a'];
            }
            transformMap[transformedWord] = 1;
        }
        return transformMap.size();
    }
};