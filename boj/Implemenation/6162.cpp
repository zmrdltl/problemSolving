#include <bits/stdc++.h>
using namespace std;
int t;

string getWetherString(int expected, int actual) {
    if(expected <= actual) return "no drought";
    string base = "drought", d;
    for(int i = actual*5; i < expected; i *= 5) d += "mega ";
    return d + base;
}

int main(){
    cin >> t;
    for(int i = 1; i <= t; i++){
        int expected, actual;
        cin >> expected >> actual;
        cout << "Data Set " << i << ':' << '\n';
        cout << getWetherString(expected, actual) << '\n';
        cout << '\n';
    }
}