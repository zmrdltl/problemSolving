#include <bits/stdc++.h>
using namespace std;
string name;
int age, weight;
int main(){
  while(1){
    cin >> name >> age >> weight;
    if(name == "#" && !age && !weight) break;
    cout << name << ' ';
    if(age > 17 || weight >= 80) cout << "Senior\n";
    else cout << "Junior\n";
  }
}