#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int solution(int n) {
    int answer = 0;
    vector <ll> d(n+1,0);
    d[0] = 1;
    for(int i = 2; i <= n; i+=2){
        d[i] = 3 * d[i-2] % 1000000007;
        for(int j = 0; j <= i - 4; j += 2)
            d[i] += 2 * d[j] % 1000000007;
    }
    return d[n] % 1000000007;
}
int main(){
    cout << solution(50);
}