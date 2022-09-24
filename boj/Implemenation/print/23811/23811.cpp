#include <bits/stdc++.h>
using namespace std;
int n;

void printLong(){
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n * 5; j++){
      cout << "@";
    }
    cout << '\n';
  }
}

void printShort(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << "@";
    }
    cout << '\n';
  }
}

int main(){
  cin >> n;
  printLong();
  printShort();
  printLong();
  printShort();
  printLong();
}