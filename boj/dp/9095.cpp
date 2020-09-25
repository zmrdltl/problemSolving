#include <iostream>
#include <cstring>
using namespace std;
int t,n;
int d[11];

int dp(int n){
    int &ret = d[n];
    if(ret!=-1) return ret;
    if(n==0) return 1;
    ret = dp(n-1) + dp(n-2) + dp(n-3);
    return ret;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        memset(d,-1,sizeof(d));
        cout << dp(n) << '\n';
    }
}