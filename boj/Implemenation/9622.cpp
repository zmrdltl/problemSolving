#include <bits/stdc++.h>
#define LEN_LIMIT 56.0
#define WID_LIMIT 45.0
#define DEP_LIMIT 25.0
#define WEI_LIMIT 7.0
using namespace std;

double l, wi, d, we, t;
int tot;

int main(){
  cin >> t;
  while(t--){
    cin >> l >> wi >> d >> we;
    if(
      (
        (l <= LEN_LIMIT && wi <= WID_LIMIT && d <= DEP_LIMIT) || l + wi + d <= 125.0)
          && we <= WEI_LIMIT
        ){
        cout << 1 << '\n';
        tot++;
    }
    else cout << 0 << '\n';
  }
  cout << tot << '\n';
}