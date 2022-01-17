#include <bits/stdc++.h>
using namespace std;
string flightNum;
int booked;
int main(){
    while(1){
        cin >> flightNum >> booked;
        if(flightNum == "#" && !booked) break;
        while(1){
            char stat;
            int num;
            cin >> stat >> num;
            if(stat == 'X' && !num) break;
            if(stat == 'B') {
                if(booked + num > 68) continue;
                booked += num;
            }
            if(stat == 'C') {
                if(booked - num < 0) continue;
                booked -= num;
            }
        }
        cout << flightNum << ' ' << booked << '\n';
    }
}