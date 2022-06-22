#include <bits/stdc++.h>
using namespace std;
int t, sum;
int main(){
  cin >> t;
  for(int i = 1; i <= t; i++){
    cin >> sum;
    printf("Case %d:\n", i);
    for(int j = 1; j <= sum/2; j++){
      if(sum-j > 6) continue;
      printf("(%d,%d)\n", j, sum-j);
    }
  }
}