class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> shortest;
        vector<int> positions;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == c) positions.push_back(i);
        }

        for(int i = 0; i < s.size(); i++) {
            int minPos = 0x3f3f3f3f;
            for(auto p : positions) {
                minPos = min(minPos, abs(i-p));
            }
            shortest.push_back(minPos);
        }
        return shortest;
    }
};