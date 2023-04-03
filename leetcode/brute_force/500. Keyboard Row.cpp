class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string firstRow = "qwertyuiop";
        string secondRow = "asdfghjkl";
        string thirdRow = "zxcvbnm";
        vector <string> ans;
        for(auto w : words) {
            int canFirst = 0, canSecond = 0, canThird = 0;
            for(auto c : w) {
                char lowerC = tolower(c); 
                for(auto f : firstRow) {
                    if(f == lowerC) {
                        canFirst++;
                    }
                }
                for(auto s : secondRow) {
                    if(s == lowerC) {
                        canSecond++;
                    }
                }
                for(auto t : thirdRow) {
                    if(t == lowerC) {
                        canThird++;
                    }
                }
            }
            if(canFirst == w.size() || canSecond == w.size() || canThird == w.size()) {
                ans.push_back(w);
            }
        }
        return ans;
    }
};