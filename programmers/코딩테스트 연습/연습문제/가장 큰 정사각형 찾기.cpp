#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board){
    int answer = 0;
    int d[1001][1001]; //i,j에서 최대 한 변 길이
    memset(d,0,sizeof(d));
    int r = board.size();
    int c = board[0].size();
    int width = 1;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(board[i][j]) {
                d[i+1][j+1] = min({d[i][j],d[i][j+1],d[i+1][j]}) + 1;
            }
        }
    }
    
    for(int i = 1; i <= r; i++){
        for(int j = 1;j <= c; j++){
            answer = max(answer,d[i][j]);
        }
    }
    return answer * answer;    
}