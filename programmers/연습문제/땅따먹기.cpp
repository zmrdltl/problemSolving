#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > land){
    int answer = 0;
    for(int k = 0; k < 4; k++){
        int idx = -1;
        int bef = k;
        int sum = land[0][k];
        for(int i = 1; i < land.size(); i++){
            int big = 0;
            for(int j = 0; j < 4; j++){
                if(bef != j && big < land[i][j]){
                    big = land[i][j];
                    idx = j;
                }
            }
            sum += big;
            bef = idx;
        }
        answer = max(answer,sum);
    }
    return answer;
}