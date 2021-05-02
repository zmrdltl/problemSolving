#include <bits/stdc++.h>
using namespace std;
int n;
int a[11],ans[11];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(a[i] == cnt) {
                if(!ans[j]) { ans[j] = i+1; break; }
            }
            else
                if(!ans[j]) cnt++;
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
}