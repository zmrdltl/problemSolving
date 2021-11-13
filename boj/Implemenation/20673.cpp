#include <bits/stdc++.h>
using namespace std;
int newCases, newHospitalizations;

string filter(){
    if(newCases <= 50 && newHospitalizations <= 10) return "White";
    if(newHospitalizations > 30) return "Red";
    return "Yellow";
}

int main(){
    cin >> newCases >> newHospitalizations;
    cout << filter();
}