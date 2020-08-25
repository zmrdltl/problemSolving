#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    int alength = a.second - a.first;
    int blength = b.second - b.first;
    if(alength == blength) return a.first < b.first;
    return alength < blength;
}

vector<int> solution(vector<string> gems) {
    map <string,int>m;
    vector <pair<int,int>> answer;
    for(auto &p : gems) m[p] = 0;
    int l=0,r=0,cnt=0;
    int gemsCategory = m.size();
    int gemsNum = gems.size();

    while(1){
        //종류별로 모았다.
        if(cnt == gemsCategory) cnt -= (--m[gems[l++]] == 0);
        else if(r==gemsNum) break;
        else cnt += (m[gems[r++]]++ == 0);  
        if(cnt == gemsCategory) answer.push_back({l+1,r});  
        // cout << cnt << '\n';
    }
    sort(answer.begin(),answer.end(), cmp);
    return {answer[0].first,answer[0].second};
}