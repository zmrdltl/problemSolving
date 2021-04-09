#include <bits/stdc++.h>
using namespace std;
using pdi = pair<double,int>;
bool cmp(pdi &a, pdi &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector <pdi> loseRatio;

    int accumulate = 0;
    int people = stages.size();
    map<int,int> loser;
    for(auto &s : stages) loser[s]++;

    for(int i = 1; i<= N; i++){
        double loseRate = (double)loser[i] / (double)(people - accumulate);
        if(people - accumulate <= 0) loseRate = 0;
        loseRatio.push_back({loseRate,i});
        accumulate += loser[i];
    }

    sort(loseRatio.begin(),loseRatio.end(),cmp);
    for(auto &l : loseRatio) answer.push_back(l.second);
    return answer;
}