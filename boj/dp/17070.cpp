#include <bits/stdc++.h>
using namespace std;
int house[20][20], n, cnt;
void backtracking(int r, int c, int dir){
    if(house[r][c]) return;
    if(r == n && c == n) { cnt++; return; }
    if(dir == 1) backtracking(r, c + 1, 1);
    if(dir == 2) backtracking(r + 1, c, 2);
    if(dir == 3) backtracking(r, c + 1, 1), backtracking(r + 1, c, 2);
    if(!house[r][c+1] && !house[r+1][c] && !house[r+1][c+1])
        backtracking(r + 1, c + 1, 3);
}
int main(){
    memset(house, 1, sizeof(house));
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) 
            cin >> house[i][j];
    
    backtracking(1,2,1);
    cout << cnt;
}