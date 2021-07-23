#include <bits/stdc++.h>
using namespace std;
string p;
int k, prime[1000001], minDiv = 0x3f3f3f3f;

void makePrime(){
    for(int i = 2; i*i <= 1000000; i++){
        if(prime[i]) continue;
        for(int j = i + i; j <= 1000000; j+=i) prime[j] = 1;
    }
}

int main(){
    cin >> p >> k;
    makePrime();
    for(int i = 2; i <= k; i++){
        int ret = 0;
        if(prime[i]) continue;
        for(int j = 0; j < p.size(); j++)
            ret = (ret * 10 + p[j] - '0') % i;
        if(!ret) { minDiv = i; break;}
    }
    if(minDiv < k) cout << "BAD" << ' ' << minDiv;
    else cout << "GOOD";
}