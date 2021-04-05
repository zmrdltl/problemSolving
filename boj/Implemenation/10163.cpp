#include <bits/stdc++.h>
using namespace std;
int n, category = 1, board[101][101];
int main(){
    cin >> n;

    for(int k = 0; k < n; k++){
        int x1,y1,width,height;
        cin >> x1 >> y1 >> height >> width;

        for(int i = x1; i < x1 + height; i++){
            for(int j = y1; j < y1 + width; j++){
                board[i][j] = category;
            }
        }
        
        category++;
    }
    
    for(int k = 1; k <= n; k++){
        int cnt = 0;
        for(int i = 0; i <= 100; i++){
            for(int j = 0; j <= 100; j++){
                if(board[i][j] == k) cnt++;
            }
        }
        cout << cnt <<'\n';
    }
}