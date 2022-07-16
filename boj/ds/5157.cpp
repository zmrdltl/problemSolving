#include <bits/stdc++.h>
using namespace std;

int k, c, b, n, r, ans;
map <int,int> bonusInfo;
vector <int> bailedCompany;

int main(){
  cin >> k;
  for(int i = 1; i <= k; i++){
    bonusInfo.clear();
    bailedCompany.clear();
    ans = 0;

    cin >> c >> b >> n >> r;

    for(int i = 0, x; i < b; i++){
      cin >> x;
      bailedCompany.push_back(x);
    }

    for(int i = 0, c, p; i < n; i++){
      cin >> c >> p;
      bonusInfo[c] += p * r/100;
    }

    for(auto b : bailedCompany){
      ans += bonusInfo[b];
    }
    cout << "Data Set " << i << ":\n";
    cout << ans << '\n' << '\n';
  }
}