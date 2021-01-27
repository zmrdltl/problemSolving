#include <bits/stdc++.h>
using namespace std;
int num[5];
int ans = 1;

int getCnt(int n){
    int cnt = 0;
    for(int i = 0; i < 5; i++)
        if(n % num[i] == 0) cnt++;
    return cnt;
}

int main(){
    for(int i = 0; i < 5; i++) cin >> num[i];
    while(getCnt(ans) < 3)
        ans++;
    cout << ans << '\n';
}