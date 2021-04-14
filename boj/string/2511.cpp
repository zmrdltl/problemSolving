#include <bits/stdc++.h>
using namespace std;
int a[10],b[10],aCnt,bCnt;
int main(){
    for(int i = 0; i < 10; i++) cin >> a[i];
    for(int i = 0; i < 10; i++) cin >> b[i];
    for(int i = 0; i < 10; i++){
        if(a[i] == b[i]) aCnt++,bCnt++;
        else if(a[i] > b[i]) aCnt+=3;
        else bCnt+=3;
    }
    cout << aCnt << ' ' << bCnt <<'\n';

    if(aCnt == bCnt && bCnt == 10) cout << "D";
    else if(aCnt == bCnt) {
        if(a[9] > b[9]) cout << "A";
        else if(a[9] < b[9]) cout << "B";
        else{
            for(int i = 9; i >= 0; i--){
                if(a[i] > b[i]) {
                    cout << "A";
                    break;
                }else if(a[i] < b[i]){
                    cout << "B";
                    break;
                }
            }
        }
    }
    else{
        if(aCnt > bCnt) cout << "A";
        else cout << "B";
    }
}