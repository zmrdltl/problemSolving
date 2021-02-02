#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int clothCnt = 0 ;
    map <string,vector<string>> comb;
    for(int i = 0; i < clothes.size(); i++) comb[clothes[i][1]].push_back(clothes[i][0]);
    for(auto category : comb)
        answer *= category.second.size() + 1;
    return answer - 1;
}
