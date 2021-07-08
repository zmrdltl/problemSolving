#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, isPrime[4000001];
vector <ll> prime;

void makePrime(){
    for(int i = 2; i*i <= 4000000; i++){
        if(!isPrime[i]){
            for(int j = i + i; j <= 4000000; j+=i) isPrime[j] = 1;
        }
    }
}

ll twoPointer(){
    ll ans = 0, sum = 0, l = 0, r = 0;
    if(prime.size()) sum = prime[0];
    while(l <= r && r < prime.size()){
        if(sum > n) sum -= prime[l++];
        else {
            if(sum == n) ans++;
            sum += prime[++r];
        }
    }
    return ans;
}

int main(){
    cin >> n;
    makePrime();
    for(int i = 2; i<=4000000; i++) if(!isPrime[i]) prime.push_back(i);
    cout << twoPointer();
}