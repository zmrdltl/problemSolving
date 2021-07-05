#include <bits/stdc++.h>
using namespace std;
int n, ans;
int chessBoard[16];

int isPossible(int row){
    for(int i = 0; i < row; i++){
        if(chessBoard[row] == chessBoard[i] || abs(chessBoard[row] - chessBoard[i]) == row - i) return false;
    }
    return true;
}

void dfs(int row){
    if(row == n) { ans++; return;}
    for(int i = 0; i < n; i++){
        chessBoard[row] = i;
        if(isPossible(row)){
            dfs(row + 1);
        }
    }

}

int main(){
    cin >> n;
    dfs(0);
    cout << ans;
}