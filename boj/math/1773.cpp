#include <bits/stdc++.h>
using namespace std;
int n,endTime,ans;
int ck[2000001], period[100];

int main(){
    cin >> n >> endTime;
    for(int i = 0; i < n; i++) cin >> period[i];
    for(int i = 0; i < n; i++){
        for(int j = period[i]; j <= endTime; j += period[i])
            ck[j] = 1;
    }
    for(int i = 1; i <= endTime; i++){
        if(ck[i]) ans++;
    }
    cout << ans << '\n';
}