#include <bits/stdc++.h>
using namespace std;

bool isMinimal(vector<int>ans,int col){
    for(int i = 0; i < ans.size(); i++){
        if((ans[i] & col) == ans[i]) return false;
    }
    return true;
}
int solution(vector<vector<string>> relation) {
    int rowSize= relation.size();
    int colSize = relation[0].size();
    vector <int> ans;
    for(int i = 1; i < (1<<colSize); i++){
        set <string> s;
        for(int j = 0; j < rowSize; j++){
            string data;
            for(int k = 0; k < colSize; k++){
                if(i & (1 << k)) //선택 조합이라면
                    data += relation[j][k];
            }
            s.insert(data);
        }
        
        if(s.size() == rowSize && isMinimal(ans,i))
            ans.push_back(i);
    }
    return ans.size();
}