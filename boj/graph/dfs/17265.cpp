#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
char board[5][5];
int maxD ,minD , n;

int cal(int a, char op, int b){
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    if(op == '*') return a * b;
    return 0;
}

int res(string s){
    int result = s[0] - '0';
    for(int i = 1; i < s.size(); i += 2)
        result = cal(result, s[i], s[i+1] - '0');
    return result;
}

int dfs(int r, int c, string s, int option){
    if(0 > r || r >= n || 0 > c || c >= n) return !option ? -INF : INF;
    if(r == n - 1 && c == n - 1) return res(s);
    int ret = !option ? -INF : INF;

    s.push_back(board[r+1][c]);
    if(!option) ret = max(ret,dfs(r + 1, c, s, option));
    else ret = min(ret,dfs(r + 1, c, s, option));
    s.pop_back();

    s.push_back(board[r][c + 1]);
    if(!option) ret = max(ret,dfs(r, c + 1, s, option));
    else ret = min(ret,dfs(r, c + 1, s, option));
    s.pop_back();
    
    return ret;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    string s = "";
    s += board[0][0];
    maxD = dfs(0, 0, s, 0);
    s = "";
    s += board[0][0];
    minD = dfs(0, 0, s, 1);
    cout << maxD << ' ' << minD;
}