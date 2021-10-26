#include <bits/stdc++.h>
using namespace std;
double t, p, consumptionRate, ans;
int main(){
    cin >> t >> p;
    if(p > 20) {
        consumptionRate = (100.0 - p) / t;
        ans += (p - 20.0) / consumptionRate;
        p -= (p - 20.0);
        ans += p / (consumptionRate / 2.0);
    }
    else {
        double x = (40.0 * t) / (60.0 - p); //80%를 x분 동안 소모
        consumptionRate = 80.0 / x / 2;
        ans = p / consumptionRate;
    }
    printf("%.6f", ans);
}