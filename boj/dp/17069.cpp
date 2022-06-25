#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll house[20][20], n, cnt;

ll backtracking(int r, int c, int dir){
    if(house[r][c]) return 0;
    if(r == n && c == n) { return 1; }

    int &ret = house[r][c];
    if(ret != -1) return ret;
    ret = 1;

    if(dir == 1) ret += backtracking(r, c + 1, 1);
    if(dir == 2) ret += backtracking(r + 1, c, 2);
    if(dir == 3) ret += backtracking(r, c + 1, 1) + backtracking(r + 1, c, 2);
    if(!house[r][c+1] && !house[r+1][c] && !house[r+1][c+1])
        ret += backtracking(r + 1, c + 1, 3);
}
int main(){
    memset(house, -1, sizeof(house));
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) 
            cin >> house[i][j];
    
    cout << backtracking(1,2,1);
    
}