//꿈틀꿈틀 애벌레 호석 - 효율성
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, food[100001],d[100001], l, r = 1, sum, energy;

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> food[i];
    for(r = 1; r <= n; r++){
        sum += food[r];
        d[r] = d[r-1];
        while(sum >= k){
            d[r] = max(d[r], d[l] + sum - k);
            sum -= food[++l];
        }
    }
    cout << d[n];
}