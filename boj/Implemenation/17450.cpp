#include <bits/stdc++.h>
using namespace std;
char snackName[] = {'S', 'N', 'U'}, ans;
float efficiency[3], best;

int main(){
  for(int i = 0; i < 3; i++) {
    float price, weight;
    cin >> price >> weight;
    price *= 10;
    weight *= 10;
    if(price >= 5000) price -= 500;
    efficiency[i] = weight / price;
    best = max(best, efficiency[i]);
  }

  for(int i = 0; i < 3; i++) {
    if(best == efficiency[i]) {
      ans = snackName[i];
      break;
    }
  }

  cout << ans;
}