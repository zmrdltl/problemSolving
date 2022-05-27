#include <bits/stdc++.h>
using namespace std;
int p, q;
vector <int> pFactor, qFactor;

vector <int> getFactor(int range){
  vector <int> factor;
  for(int i = 1; i <= range; i++){
    if(range % i == 0) factor.push_back(i);
  }
  return factor;
}

int main(){
  cin >> p >> q;
  pFactor = getFactor(p);
  qFactor = getFactor(q);
  for(auto pf : pFactor){
    for(auto qf : qFactor){
      cout << pf << ' ' << qf << '\n';
    }
  }
}