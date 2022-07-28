#include <bits/stdc++.h>
using namespace std;

map <string, double> sizePerType;
double n, c, totalSize, sz;
string type;

int main(){
  cin >> n >> c;

  while(n--){
    cin >> sz >> type;
    sizePerType[type] += sz;
    totalSize += sz;
  }
  
  cout << totalSize << '\n' << sizePerType["bedroom"] << '\n';
  printf("%.6f\n", c * (totalSize - sizePerType["balcony"]/2));
}