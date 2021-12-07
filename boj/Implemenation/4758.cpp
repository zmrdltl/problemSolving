#include <bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        bool hasPosition = false;
        double speed, weight, strength;
        cin >> speed >> weight >> strength;
        if(!speed && !weight && !strength) break;
        if(speed <= 4.5 && weight >= 150 && strength >= 200) 
            hasPosition = true, cout << "Wide Receiver ";
        if(speed <= 6.0 && weight >= 300 && strength >= 500) 
            hasPosition = true, cout << "Lineman ";
        if(speed <= 5.0 && weight >= 200 && strength >= 300) 
            hasPosition = true, cout << "Quarterback ";
        if(!hasPosition) cout << "No positions";
        cout << '\n';
    }
}