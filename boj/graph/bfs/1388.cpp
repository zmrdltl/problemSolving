#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int n, m, ck[101][101], ans;
char room[101][101];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> room[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ck[i][j]) continue;
            ans++;
            ck[i][j] = 1;
            char shape = room[i][j];
            if(shape == '-'){
                for(int k = j + 1; k < m; k++){
                    if(room[i][k] == '|') break;
                    ck[i][k] = 1;
                }
            }
            else{
                for(int k = i + 1; k < n; k++){
                    if(room[k][j] == '-') break;
                    ck[k][j] = 1;
                }
            }
        }
    }
    cout << ans;
}