#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector <int> releaseDay;
    for(int i = 0; i < progresses.size(); i++){
        int rDay = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] == 0){
            releaseDay.push_back(rDay);
        }else{
            releaseDay.push_back(rDay + 1);
        }
    }
    int funcCnt = 1;
    int pivot = 0;
    for(int i = 1; i < releaseDay.size(); i++){
        if(releaseDay[pivot] >= releaseDay[i]){
            funcCnt++;
        }else{
            pivot = i;
            answer.push_back(funcCnt);
            funcCnt = 1;
        }
        if( i== releaseDay.size() - 1) answer.push_back(funcCnt);
    }
    for(auto r : releaseDay) cout << r << ' ';
    return answer;
}