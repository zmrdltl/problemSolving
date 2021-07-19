#include <bits/stdc++.h>
using namespace std;
int n, m;
int num[101];
set <int> numSets;
int gcd(int a, int b){
    if(!b) return a;
    return gcd(b,a%b);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int i = 1; i < n; i++) m = gcd(abs(num[i] - num[i-1]),m);
    for(int i = 1; i <= sqrt(m); i++){
        if(m % i == 0){
            numSets.insert(i);
            numSets.insert(m/i);
        }
    }
    for(auto n : numSets) if(n != 1) cout << n << ' ';
}