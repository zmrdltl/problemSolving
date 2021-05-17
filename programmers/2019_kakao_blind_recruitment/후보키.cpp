#include <bits/stdc++.h>
using namespace std;

bool isMinimal(vector<int> vec,int now){
    for(int i = 0; i < vec.size(); i++)
        if((vec[i] & now) == vec[i]) return false;
    return true;
}

int solution(vector<vector<string>> relation) {
    int rowSize = relation.size(); 
    int colSize = relation[0].size();
    vector<int> ans;
    for(int i = 1; i < (1<<colSize); i++){
        set<string> s; //
        for(int j = 0; j < rowSize; j++){
            string now = "";
            for(int k = 0; k < colSize; k++){
                // 선택된 컬럼과 일치한다면
                if(i & (1<<k))
                    now += relation[j][k];
            }
            s.insert(now);
        }
        if(s.size() == rowSize && isMinimal(ans,i))
            ans.push_back(i);
    }
    return ans.size();
}