#include <bits/stdc++.h>
using namespace std;
int n, mind;
vector <string> appearance(100);
char ans[100][100];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> appearance[i];
    }
    cin >> mind;
    if(mind == 1){
        for(int i = 0; i < n; i++)
            cout << appearance[i] << '\n';
    }else if(mind == 2){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                ans[i][j] = appearance[i][n-1-j];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << ans[i][j];
            cout << '\n';
        }
    }else{
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                ans[i][j] = appearance[n - 1 - i][j];
        for(int i = 0; i < n; i++)
            cout << ans[i]<<'\n';
    }
}