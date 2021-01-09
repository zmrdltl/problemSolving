#include <bits/stdc++.h>
using namespace std;

int n, m;
char square[51][51];

int main(){
    cin >> n >> m;
    int length = max(n,m);
    int ans = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> square[i][j];
        
    for(int k = 1; k <= length; k++){
        for(int i = 1; i <= n ; i++){
            for(int j = 1; j <= m; j++){
                if(k + i > n || k + j > m) continue;
                int a1 = square[i][j]-'0';
                int a2 = square[i][j+k]-'0';
                int a3 = square[i+k][j]-'0';
                int a4 = square[i+k][j+k]-'0';
                if(a1==a2&&a2==a3&&a3==a4) ans = max(ans,(k+1)*(k+1));
            }
        }
    }
    cout << ans <<'\n';
}