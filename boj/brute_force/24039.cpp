#include <bits/stdc++.h>
using namespace std;
vector <int> prime;
int ck[10001], n, ans;

void makePrime(){
    for(int i = 2; i*i <= 10000; i++){
        if(ck[i]) continue;
        for(int j = i+i; j <= 10000; j += i) ck[j] = 1;
    }

    for(int i = 2; i <= 10000; i++){
        if(!ck[i]) prime.push_back(i);
    }
}

int main(){
    makePrime();
    cin >> n;
    for(int i = 0; i < prime.size() - 1; i++){
        int mul = prime[i] * prime[i+1];
        if(mul > n) {ans = mul; break;}
    }
    cout << ans;
}