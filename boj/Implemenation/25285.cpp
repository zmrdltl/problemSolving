#include <bits/stdc++.h>
using namespace std;
double t, cm, kg, bmi;

int getBodyClass(){
    bmi = kg/pow(cm/100,2);
    if(cm < 140.1) return 6;
    if(140.1 <= cm && cm < 146) return 5;
    if(146 <= cm && cm < 159) return 4;
    if(159 <= cm && cm < 161){
        if(16 <= bmi && bmi < 35) return 3;
        return 4;
    }
    if(161 <= cm && cm < 204){
        if(20 <= bmi && bmi < 25) return 1;
        else if((18.5 <= bmi && bmi < 20) | (25 <= bmi && bmi < 30)) return 2;
        else if((16 <= bmi && bmi < 18.5) | (30 <= bmi && bmi < 35)) return 3;
        return 4;
    }
    return 4;
}

int main() {
    cin >> t;
    while(t--){
        cin >> cm >> kg;
        cout << getBodyClass() << '\n';
    }
}