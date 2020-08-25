#include <iostream>
#define ll long long
using namespace std;
ll f[90];
ll fibo(int n){
    ll &ret = f[n];
    if(n==0) return ret = 0;
    if(n<=2) return ret = 1;
    if(ret) return ret;
    return ret = fibo(n-1) + fibo(n-2);
}
int main(){
    int n;
    cin >> n;
    cout << fibo(n) << '\n';
}
