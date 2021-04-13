#include <bits/stdc++.h>
using namespace std;
int n, ans = 1;
char board[51][51];

int getCandy(){
    int ans = 1, ans1 = 1;
    for(int i = 0; i < n; i++){
        int cnt = 1, cnt1 = 1;
        for(int j = 0; j < n - 1; j++){
            if(board[i][j] == board[i][j+1]) cnt++;
            else ans = max(ans, cnt), cnt = 1;
            if(board[j][i] == board[j+1][i]) cnt1++;
            else ans1 = max(ans1, cnt1), cnt1 = 1;
        }
        ans = max(ans,cnt);
        ans1 = max(ans1,cnt1);
    }
    return max(ans,ans1);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> board[i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            swap(board[i][j],board[i][j+1]);
            ans = max(ans,getCandy());
            swap(board[i][j],board[i][j+1]);

            swap(board[j][i],board[j+1][i]);
            ans = max(ans,getCandy());
            swap(board[j][i],board[j+1][i]);
        }
    }

    cout << ans;
}