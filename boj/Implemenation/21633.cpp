#include <bits/stdc++.h>
using namespace std;
double k, ans;
int main(){
    cin >> k;
    ans = 25.0 + k * 0.01;
    if(ans <= 100) printf("100.00");
    else if(ans >= 2000) printf("2000.00");
    else printf("%.2f", ans);
}