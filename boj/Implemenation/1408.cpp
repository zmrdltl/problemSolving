#include <bits/stdc++.h>
using namespace std;
int s[3], e[3];

string getTimeLeft(){
    int startTime = 0, endTime = 0, hour, minute, sec;
    string timeLeft = "";
    
    startTime = s[0] * 3600 + s[1] * 60 + s[2];
    endTime = e[0] * 3600 + e[1] * 60 + e[2];

    if(startTime > endTime) endTime += 3600 * 24;
    sec = endTime - startTime;

    hour = sec / 3600;
    if(hour == 24) hour = 0;
    sec %= 3600;
    if(hour < 10) timeLeft += "0";
    timeLeft += to_string(hour) + ":";

    minute = sec / 60;
    if(minute < 10) timeLeft += "0";
    timeLeft += to_string(minute) + ":";
    sec %= 60;

    if(sec < 10) timeLeft += "0";
    timeLeft += to_string(sec);

    return timeLeft;
}

int main(){
    scanf("%d:%d:%d", &s[0], &s[1], &s[2]);
    scanf("%d:%d:%d", &e[0], &e[1], &e[2]);
    cout << getTimeLeft();
}