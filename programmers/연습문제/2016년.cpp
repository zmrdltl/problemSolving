#include <bits/stdc++.h>
using namespace std;

int getDay(int month){
    if(month==1) return 31;
    if(month==2) return 29;
    if(month==3) return 31;
    if(month==4) return 30;
    if(month==5) return 31;
    if(month==6) return 30;
    if(month==7) return 31;
    if(month==8) return 31;
    if(month==9) return 30;
    if(month==10) return 31;
    if(month==11) return 30;
    if(month==12) return 31;
}

string whichDay(int day){
    if(day%7==1) return "FRI";
    if(day%7==2) return "SAT";
    if(day%7==3) return "SUN";
    if(day%7==4) return "MON";
    if(day%7==5) return "TUE";
    if(day%7==6) return "WED";
    if(day%7==0) return "THU";
}

string solution(int a, int b) {
    string answer = "";
    int day = 0;
    for(int i = 1; i < a; i++){
        day += getDay(i);
    }
    day += b;
    return whichDay(day);
}