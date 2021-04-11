#include <bits/stdc++.h>
using namespace std;
int n, ans;
int mountain[300001];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> mountain[i];
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = i+1; j < n; j++){
            if(mountain[i] >= mountain[j]) cnt++, ans = max(ans,cnt);
            else { i = j-1; break; }
        }
    }
    cout << ans << '\n';
}