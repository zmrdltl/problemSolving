#include <bits/stdc++.h>
using namespace std;
int k, head;
string behaving;
int main(){
  cin >> k;
  for(int i = 1; i <= k; i++){
    cin >> head;
    cin >> behaving;
    for(auto b : behaving) {
      if(b == 'c') head++;
      else head--;
    }
    cout << "Data Set " << i << ":\n" << head << "\n\n";
  }
}