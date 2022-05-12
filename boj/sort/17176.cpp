#include <bits/stdc++.h>
using namespace std;
string cryptogram, origin;
vector <int> cryptogramVector;
int n;

void decodeCryptogram(){
  for(auto c : cryptogramVector){
    if(c == 0) cryptogram += " ";
    else if(1 <= c && c <= 26) {
      cryptogram += (c - 1) + 'A';
    }
    else if(27 <= c && c <= 52) {
      cryptogram += (c - 27) + 'a';
    }
  }
}

int main(){
  cin >> n;
  cryptogramVector.resize(n);
  for(int i = 0; i < n; i++) cin >> cryptogramVector[i];
  cin.ignore();

  getline(cin, origin);
  decodeCryptogram();

  sort(cryptogram.begin(), cryptogram.end());
  sort(origin.begin(), origin.end());
  
  if(cryptogram == origin) cout << 'y';
  else cout << 'n';
}