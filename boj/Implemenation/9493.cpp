#include <bits/stdc++.h>
using namespace std;
double m, a, b;

string getTimeString(double t){
    string tmp;
    int ti = t, hour, minute, sec;

    hour = ti / 3600;
    tmp += to_string(hour) + ":";
    ti %= 3600;

    minute = ti / 60;
    if(minute < 10) tmp += "0";
    tmp += to_string(minute) + ":";
    ti %= 60;

    sec = ti;
    if(sec < 10) tmp += "0";
    tmp += to_string(sec);
    
    return tmp + "\n";
}

int main(){
    while(1){
        cin >> m >> a >> b;
        if(!m && !a && !b) break;
        double aTime = m * 3600 / a;
        double bTime = m * 3600 / b;
        cout << getTimeString(round(aTime - bTime));
    }
}