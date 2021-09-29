#include <bits/stdc++.h>
using namespace std;
int countNum[200001];
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        memset(countNum,0,sizeof(countNum));

        vector <int> ans;

        if(changed.size() % 2) return ans;

        sort(changed.begin(), changed.end());

        for(auto c : changed) countNum[c]++;

        for(int i = 0; i < changed.size(); i++){
            int c = changed[i];
            if(!countNum[c]) continue;
            if(!countNum[c*2]) return vector<int>();
            countNum[c]--, countNum[c*2]--;
            ans.push_back(c);
        }
        return ans;
    }
};
