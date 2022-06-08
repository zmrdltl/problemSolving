#include <bits/stdc++.h>
using namespace std;
int n, m, GCD;

int gcd(int a, int b){
  if(!b) return a;
  return gcd(b, a%b);
}

int main(){
  scanf("%d:%d",&n,&m);
  GCD = gcd(n, m);
  cout << n / GCD << ":" << m / GCD;
}