#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > land){
    int answer = 0;
    int d[100001][4];
    memset(d,0,sizeof(d));
    for(int i = 0; i < 4; i++)
        d[0][i] = land[0][i];
    
    for(int i = 0; i < land.size() - 1; i++){
        d[i+1][0] += max({d[i][1],d[i][2],d[i][3]}) + land[i+1][0];
        d[i+1][1] += max({d[i][0],d[i][2],d[i][3]}) + land[i+1][1];
        d[i+1][2] += max({d[i][0],d[i][1],d[i][3]}) + land[i+1][2];
        d[i+1][3] += max({d[i][0],d[i][1],d[i][2]}) + land[i+1][3];
    }

    for(int i = 0; i < 4; i++)
        answer = max(answer,d[land.size()-1][i]);
    return answer;
}