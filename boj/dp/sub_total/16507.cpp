#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll r, c, q, board[1001][1001], sum[1001][1001];
int main(){
    cin >> r >> c >> q;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> board[i][j];
        } 
    }
    
    //가로 방향으로 구간합
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            sum[i][j] = sum[i][j-1] + board[i][j];
        }
    }
    //세로 방향으로 구간합
    for(int i = 1; i <= c; i++){
        for(int j = 1; j <= r; j++){
            sum[j][i] = sum[j-1][i] + sum[j][i];
        }
    }
    
    while(q--){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << (sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1]) / ((r2 - r1 + 1) * (c2- c1 + 1)) << '\n';
    }
}