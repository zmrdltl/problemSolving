#include <bits/stdc++.h>
using namespace std;

int n, b, h, w, pricePerPerson, capacityPerWeek, minPrice = 0x3f3f3f3f;

int main(){
  cin >> n >> b >> h >> w;

  for(int i = 0; i < h; i++) {
    cin >> pricePerPerson;
    for(int j = 0; j < w; j++){
      cin >> capacityPerWeek;      
      if(capacityPerWeek < n) continue;
      if(b < n * pricePerPerson) continue;
      minPrice = min(minPrice, n*pricePerPerson);
    }
  }
  if(minPrice == 0x3f3f3f3f) cout << "stay home";
  else cout << minPrice;
}