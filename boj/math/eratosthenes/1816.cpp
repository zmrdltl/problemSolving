#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, ck[1000001];
vector <int> prime;

void makePrime(){
  for(ll i = 2; i <= 1000000; i++){
    if(ck[i]) continue;
    for(ll j = i + i; j <= i; j += i){
      ck[j] = 1;
    }
  }
  for(ll i = 2; i <= 1000000; i++){
    if(!ck[i]) prime.push_back(i);
  }
}

bool isValid(ll num){
  for(auto p : prime){
    if(num % p == 0) return false;
  }
  return true;
}

int main(){
  cin >> n;
  makePrime();
  for(ll i = 0, num; i < n; i++) {
    cin >> num;
    if(isValid(num)) cout << "YES\n";
    else cout << "NO\n";
  }
}