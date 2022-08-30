#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, ans = 1;
vector <ll> nums;
int main(){
  cin >> n >> m;
  nums.resize(n);
  for(int i = 0; i < n; i++){
    cin >> nums[i];
  }
  for(auto num : nums){
    ans *= (num % m);
    ans %= m;
  }
  cout << ans;
}