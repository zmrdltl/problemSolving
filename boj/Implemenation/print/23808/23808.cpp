#include <bits/stdc++.h>
using namespace std;
int n;

void printOther(){
  for(int i = 0; i < n; i++){
    for(int j = 1; j <= n * 5; j++){
      if(j <= n || j > n * 4) cout << '@';
      else cout << ' ';
    }
    cout << '\n';
  }
}

void printSquare(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n * 5; j++){
      cout << '@';
    }
    cout << '\n';
  }
}

int main(){
  cin >> n;
  printOther();
  printOther();
  printSquare();
  printOther();
  printSquare();
}