#include <bits/stdc++.h>
using namespace std;
int a,b,cnt[15] , mx, idx;
int main(){
    cin >> a >> b;
    cnt[a]++;
    cnt[b]++;
    for(int i = 1; i <= 13; i++){
        if(cnt[i] >= mx){
            mx = cnt[i];
            idx = i;
        }
    }
    cout << idx;
}