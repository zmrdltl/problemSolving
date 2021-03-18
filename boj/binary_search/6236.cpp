#include <bits/stdc++.h>
using namespace std;
int n,m;
int money[100001];

bool ck(int mid){
    int curMoney = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(money[i] > mid) return false;
        if(curMoney - money[i] < 0) curMoney = mid, cnt++;
        curMoney -= money[i];
    }
    return cnt <= m;
}

int binarySearch(){
    int l = 0;
    int r = 0x3f3f3f3f;
    int ans = 0x7f7f7f7f;

    while(l<=r){
        int mid = (l+r)/2;
        
        if(ck(mid))
            ans = mid,r = mid - 1;
        else l = mid + 1;
    }

    return ans;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> money[i];
    cout << binarySearch();
}