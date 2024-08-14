class Solution {
public:
  vector <string> split(string input) {
    vector <string> words;
    stringstream ss(input);
    string tmp;
    while(getline(ss, tmp, ' ')) {
      words.push_back(tmp);
    }
    return words;
  }
  string truncateSentence(string s, int k) {
    vector <string> words = split(s);
    string ans = "";
    for(int i = 0; i < k; i++) {
      ans += words[i];
      if(i != k-1) {
        ans += " ";
      }
    }
    return ans;
  }
};