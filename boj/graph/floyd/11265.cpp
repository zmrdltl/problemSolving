#include <bits/stdc++.h>
using namespace std;
int party[501][501], n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> party[i][j];
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(party[i][k] + party[k][j] < party[i][j]){
                    party[i][j] = party[i][k] + party[k][j];
                }
            }
        }
    }
    
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        if(party[a][b] <= c) cout << "Enjoy other party\n";
        else cout << "Stay here\n";
    }
}