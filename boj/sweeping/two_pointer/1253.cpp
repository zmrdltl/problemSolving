#include <bits/stdc++.h>
using namespace std;
int n, ans, num[2001];

bool isAllZero(){
    for(int i = 0; i < n; i++)
        if(num[i]) return false;
    return true;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++) cin >> num[i];

    if(isAllZero()){ cout << n; return 0; }

    sort(num, num + n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            auto idx = lower_bound(num , num + n, num[i] - num[j]) - num;
            if(idx == i || idx == j) continue;
            if(num[idx] + num[j] == num[i]) {
                ans++; break;
            }
        }
    }
    
    cout << ans;
}