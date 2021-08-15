#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll num;
ll binarySearch(){
    ll l = 0;
    ll r = sqrt(num);
    while(l <= r){
        ll mid = (l + r) / 2;
        if(mid  < sqrt(num)) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
int main(){
    cin >> num;
    cout << binarySearch();
}