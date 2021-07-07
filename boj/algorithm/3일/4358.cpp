#include <bits/stdc++.h>
using namespace std;
map <string,double> m;
double totalCnt;
string s;

int main(){
    while(getline(cin,s)) m[s]++;
    for(auto el : m) totalCnt += el.second;
    for(auto el : m){
        cout << el.first << ' ';
        printf("%.4f\n",el.second / totalCnt * 100);
    }
}