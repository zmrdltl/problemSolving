#include <bits/stdc++.h>
using namespace std;
int winCnt;
int main(){
    for(int i = 0; i < 6; i++){
        char info;
        cin >> info;
        if(info == 'W') winCnt++;
    }
    if(!winCnt) cout << -1;
    else if(winCnt >= 5) cout << 1;
    else if(winCnt >= 3) cout << 2;
    else cout << 3;
}