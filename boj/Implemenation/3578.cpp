#include <bits/stdc++.h>
using namespace std;
int h;
int main(){
  cin >> h;
  if(!h) {cout << 1; return 0;}
  if(h==1) {cout << 0; return 0;}

  if(h%2) cout << 4;
  for(int i = 0; i < h/2; i++) cout << "8";
}