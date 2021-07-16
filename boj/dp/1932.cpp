#include <bits/stdc++.h>
using namespace std;
int n, triangle[505][505], d[505][505], ans;


int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> triangle[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            d[i][j] = max(d[i-1][j-1],d[i-1][j])  + triangle[i][j];
        }
    }

    for(int i = 1; i <= n; i++) ans = max(ans,d[n][i]);
    cout << ans;
}