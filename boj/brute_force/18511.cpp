#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
vector <int> setK, permutation;

void dfs(int depth, int length){
  if(depth == length) {
    int madeNum = 0;
    for(auto p : permutation) {
      madeNum += p;
      madeNum *= 10;
    }
    madeNum /= 10;
    if(n >= madeNum) ans = max(ans, madeNum);
    return;
  }
  for(int i = 0; i < k; i++){
    permutation.push_back(setK[i]);
    dfs(depth+1, length);
    permutation.pop_back();
  }
}

int main(){
  cin >> n >> k;
  setK.resize(k);
  for(int i = 0; i < k; i++) cin >> setK[i];
  for(int i = 1; i <= to_string(n).size(); i++) dfs(0, i);
  cout << ans;
}