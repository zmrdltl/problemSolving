#include <bits/stdc++.h>
using namespace std;
int nowTime[3], doTime[3];
int sec1,sec2,waitTime;
string getAns(){
    string tmp ="";
    if(waitTime / 3600 < 10) tmp += "0";
    if(waitTime / 3600 >= 24) {
        int newTime = waitTime/3600 - 24;
        if(newTime < 10) tmp += "0";
        tmp += to_string(newTime) + ":";
    }
    else tmp += to_string(waitTime / 3600) + ":";
    waitTime %= 3600;
    if(waitTime / 60 < 10) tmp += "0";
    tmp += to_string(waitTime / 60) + ":";
    waitTime %= 60;
    if(waitTime < 10) tmp +="0";
    tmp += to_string(waitTime);
    return tmp;
}

int main(){
    scanf("%d:%d:%d",&nowTime[0],&nowTime[1],&nowTime[2]);
    scanf("%d:%d:%d",&doTime[0],&doTime[1],&doTime[2]);
    sec1 = nowTime[0] * 3600 + nowTime[1] * 60 + nowTime[2];
    sec2 = doTime[0] * 3600 + doTime[1] * 60 + doTime[2];
    if(sec1==sec2) cout << "24:00:00\n";
    else {
        waitTime = 24 * 3600 - sec1 + sec2;
        cout << getAns();
    }
}