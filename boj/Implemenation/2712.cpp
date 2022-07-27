#include <bits/stdc++.h>
using namespace std;
double t, weight;
string unit;

double getConvertedWeight(){
  if(unit == "kg") {
    unit = "lb";
    return weight * 2.2046;
  }
  if(unit == "lb"){
    unit = "kg";
    return weight * 0.4536;
  } 
  if(unit == "l") {
    unit = "g";
    return weight * 0.2642;
  }
  unit = "l";
  return weight * 3.7854;
}

int main(){
  cin >> t;
  while(t--){
    cin >> weight >> unit;
    printf("%.4f", getConvertedWeight());
    cout << " " << unit << '\n';
  }
}