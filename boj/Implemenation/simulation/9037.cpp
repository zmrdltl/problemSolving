#include <bits/stdc++.h>
using namespace std;
int t, n, c, cycle;
vector <int> candyState;

bool isAllHaveSameCandy(){
  for(int i = 0; i < n - 1; i++)
    if(candyState[i] != candyState[i+1]) 
      return false;
  return true;
}

void giveCandyToRightChild(){
  vector <int> tmp(n);
  for(int i = 0; i < n - 1; i++){
    tmp[i+1] = candyState[i] / 2;
  }
  tmp[0] = candyState[n - 1] / 2;
  for(int i = 0; i < n; i++){
    candyState[i] = candyState[i] / 2 + tmp[i];
  }
}

void giveCandyWhoHasOdd(){
  for(int i = 0; i < n; i++)
    if(candyState[i] % 2) 
      candyState[i]++;
}

int main(){
  cin >> t;
  
  while(t--){
    cin >> n;
    cycle = 0;
    candyState.resize(n);
    for(int i = 0; i < n; i++) cin >> candyState[i];

    giveCandyWhoHasOdd();
    while(!isAllHaveSameCandy()){
      cycle++;
      giveCandyToRightChild();
      giveCandyWhoHasOdd();
    }
    cout << cycle << '\n';
  }
}