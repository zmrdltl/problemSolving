#include <bits/stdc++.h>
using namespace std;
int trivialNum = 111;
int main(){
  for(int top = 100; top <= 999; top++){
    for(int bottom = 100; bottom <= 999; bottom++){
      if(top % trivialNum == 0 && bottom % trivialNum == 0) continue;
      if(bottom*(top / 10) == top*(bottom % 100) && (top % 10) == (bottom /100))
        printf("%d / %d = %d / %d\n", top, bottom, top/10, bottom%100);
    }
  }
}