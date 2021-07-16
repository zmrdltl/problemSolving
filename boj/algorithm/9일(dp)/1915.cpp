#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, m, ans;
int square[1001][1001], d[1001][1001];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%1d", &square[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(square[i][j]){
                square[i][j] = min({square[i-1][j-1],square[i-1][j],square[i][j-1]}) + 1;
                ans = max(ans,square[i][j]);
            }
        }
    }
    cout << ans * ans;
}