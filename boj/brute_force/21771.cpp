#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
char board[101][101];
int r, c, rg, rp, cg, cp, pCnt;
int main(){
    cin >> r >> c;
    cin >> rg >> cg >> rp >> cp;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> board[i][j];
            if(board[i][j] == 'P') pCnt++;
        }
    }
    if(pCnt == rp * cp) cout << 0;
    else cout << 1;
}