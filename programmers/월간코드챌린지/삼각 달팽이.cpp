#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int snail[1001][1001];
    int x = 0, y = 0, state = 0, num = 1;
    for(int i = 0; i < n; i++){
        if(state == 0){
            for(int j = i; j < n; j++)
                snail[x++][y] = num++;
            x--; y++;
            state = 1;
            continue;
        }
        
        if(state == 1){
            for(int j = i; j < n; j++)
                snail[x][y++] = num++;
            x--; y-=2;
            state = 2;
            continue;
        }
        
        if(state == 2){
            for(int j = i; j < n; j++)
                snail[x--][y--] = num++;
            x+=2; y++;
            state = 0;
        }
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(snail[i][j]) answer.push_back(snail[i][j]);
    return answer;
}