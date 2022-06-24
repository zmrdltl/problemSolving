#include <bits/stdc++.h>
using namespace std;
int home[35][35], n;

int dp(){
  
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j ++){
      cin >> home[i][j];
    }
  }
  home[0][0] = 1;
  home[0][1] = 2;
  cout << dp();
}