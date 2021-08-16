#include <iostream>
using namespace std;
int n, k, l = 1, r = 0x3f3f3f3f;
int main(){
    cin >> n >> k;
    while(l <= r){
        int mid = (l + r) / 2;
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            cnt += min(n,mid / i);
        if(cnt >= k) r = mid - 1;
        else l = mid + 1;
    }
    cout << l;
}