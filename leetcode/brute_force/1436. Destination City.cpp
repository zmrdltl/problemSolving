class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string curCity = paths[0][1];
        for(;;) {
            int findNext = 0;
            for(int j = 1; j < paths.size(); j++) {
                string start = paths[j][0];
                string next = paths[j][1];
                if(curCity == start) {
                    curCity = next;
                    findNext = 1;
                    break;
                }
            }
            if(!findNext) {
                break;
            }
        }
        return curCity;
    }
};