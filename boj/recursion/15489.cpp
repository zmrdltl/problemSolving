#include <bits/stdc++.h>
using namespace std;
int r, c, w, pas[31][31], ans;

void makePascal(){
    for(int i = 1; i <= 30; i++) {
        for(int j = 1; j <= i; j++){
            if(i == 1 || j == 1) pas[i][j] = 1;
            else pas[i][j] = pas[i-1][j] + pas[i-1][j-1];
        }
    }
}

int main(){
    cin >> r >> c >> w;
    makePascal();

    for(int i = r; i < r + w; i++){
        for(int j = c; j <= c + i - r; j++) {
            ans += pas[i][j];
        }
    }

    cout << ans;    
}