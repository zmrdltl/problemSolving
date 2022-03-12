#include <bits/stdc++.h>
using namespace std;
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};
bool ans = true;
int curX, curY, oriX, oriY, visited[6][6];
string s;
vector <string> v;

bool canGo(int curx, int cury, int x, int y){
    int can = 0;
    for(int i = 0; i < 8; i++){
        int nx = curx + dx[i];
        int ny = cury + dy[i];
        if(nx < 0 || nx > 5 || ny < 0 || ny > 5)continue;
        if(nx == x && ny == y) return true;
    }
    return false;
}

bool isAllVisited(){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(!visited[i][j]) return false;
        }
    }
    return true;
}

int main(){
    v.resize(36);
    cin >> s;
    curX = s[0] - 'A';
    curY = s[1] - '1';
    oriX = curX;
    oriY = curY;
    visited[oriX][oriY] = 1;
    for(int i = 1; i < 36; i++){
        cin >> s;
        int x, y;
        x = s[0] - 'A';
        y = s[1] - '1';
        if(!canGo(curX, curY, x, y)) ans = false;
        curX = x;
        curY = y;
        visited[curX][curY] = 1;
    }
    if(ans) {
        if(canGo(curX, curY, oriX, oriY) && isAllVisited()) cout << "Valid";
        else cout << "Invalid";
    }
    else cout << "Invalid";
}