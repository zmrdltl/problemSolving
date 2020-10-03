#include <iostream>
#include <vector>
#include <cmath>
#define ull unsigned long long
using namespace std;
ull binarySearch(ull n){
    ull l = 1;
    ull r = sqrt(n) * 2;
    ull mid = 0;
    ull ans = 0;
    while(l<=r){
        mid = (l+r)/2;
        if(mid*(mid+1) <= 2 * n) ans = max(ans,mid), l = mid+1;
        else r = mid-1;
    }
    return ans;
}
int main(){
    ull t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << binarySearch(n) << '\n';
    }
}