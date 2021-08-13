#include <bits/stdc++.h>
using namespace std;
int n, m, dir, cnt, curR = 1, curC = 1;
int ck[101][101];
//©Л,го,аб,╩С
int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};
int main(){
    cin >> n >> m;
    ck[1][1] = 1;
    while(1){
        curR += dr[dir];
        curC += dc[dir];
        if(1 > curR || curR > n || 1 > curC || curC > m || ck[curR][curC]){
            curR -= dr[dir];
            curC -= dc[dir];
            dir = (dir + 1) % 4;
            if(ck[curR + dr[dir]][curC + dc[dir]]) break;
            cnt++;
        }
        ck[curR][curC] = 1;
    }
    cout << cnt;
}