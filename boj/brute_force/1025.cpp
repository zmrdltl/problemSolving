#include <bits/stdc++.h>
using namespace std;

int n, m, ans = -1, chart[10][10];

bool isSquare(int num){
    int root = (int)sqrt(num);
    return root * root == num;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            scanf("%1d", &chart[i][j]);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int x = -n; x < n; x++){
                for(int y = -m; y < m; y++){
                    if(!x && !y) continue;
                    int r = i, c = j, num = 0;
                    while(0 <= r && r < n && 0 <= c && c < m){
                        num *= 10;
                        num += chart[r][c];
                        r += x, c += y;
                        if(isSquare(num)) ans = max(ans, num);
                    }
                }
            }
        }
    }
    cout << ans;
}