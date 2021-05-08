#include <bits/stdc++.h>

using namespace std;
vector <int> a;
map<string,int> m;
int ck[10];
void dfs(int depth, int idx, vector<vector<int>> caseArr){
    if(depth == caseArr.size()){
        string ans ="";
        for(auto el:a) ans += to_string(el);
        sort(ans.begin(),ans.end());
        m[ans] = 1;
        return ;
    }
    for(int i = 0; i < caseArr[idx].size(); i++){
        if(ck[caseArr[idx][i]]) continue;
        a.push_back(caseArr[idx][i]);
        ck[caseArr[idx][i]] = 1;
        dfs(depth+1,idx+1,caseArr);
        ck[caseArr[idx][i]] = 0;
        a.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    a.clear();
    m.clear();
    memset(ck,0,sizeof(ck));
    vector <vector<int>> caseArr;

    for(int i = 0; i < banned_id.size(); i++){
        int cnt = 0;
        vector<int>comb;
        for(int j = 0; j < user_id.size(); j++){
            if(banned_id[i].size()!=user_id[j].size()) continue;
            int matchFlag = 1;
            for(int k = 0; k < banned_id[i].size(); k++){
                if(banned_id[i][k] == '*') continue;
                if(banned_id[i][k]!=user_id[j][k]) {
                    matchFlag = 0;
                    break;
                }
            }
            if(matchFlag) {
                comb.push_back(j);
            }
        }

        caseArr.push_back(comb);
        comb.clear();
    }

    dfs(0,0,caseArr);

    return m.size();
}
