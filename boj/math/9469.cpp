#include <bits/stdc++.h>
using namespace std;
double d, a, b, f, timeLeft;
int p, n;
int main(){
  cin >> p;
  while(p--){
    cin >> n >> d >> a >> b >> f;
    timeLeft = d / (a + b);
    printf("%d %f\n", n, f * timeLeft);
  }
}