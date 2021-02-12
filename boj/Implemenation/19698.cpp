#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,w,h,l;
    int ho,vi;
    cin >> n >> w >> h >> l;
    ho = w / l;
    vi = h / l;
    if(ho * vi > n) cout << n <<'\n';
    else cout << ho * vi <<'\n';
}