#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int snail[1001][1001] = {0, };
    int x = 0, y = 0, state = 0, num = 1;
    for(int i = 0; i < n; i++){
        cout << "x , y : "<< x << ' ' << y <<'\n';
        if(state == 0){
            
            for(int j = i; j < n - 1; j++){
                snail[x++][y] = num++;
            }
            
            state = 1;
            continue;
        }
        if(state == 1){
            
            for(int j = i; j < n; j++){
                snail[x][y++] = num++;
            }
            state = 2;
            continue;
            
        }else{
            for(int j = i; j < n; j++){
                snail[x--][y--] = num++;
            }
            state = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(snail[i][j]){
                answer.push_back(snail[i][j]);
            }
        }
    }
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << ' ';
    }
    return answer;
}