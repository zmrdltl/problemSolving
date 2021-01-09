#include <bits/stdc++.h>
using namespace std;
int n, k;

string getStringSec(int sec){
    string tmp = "";
    int hour =  sec / 3600;
    if(hour < 10)tmp += "0";
    tmp += to_string(hour);
    sec %= 3600;
    int minute = sec / 60;
    if(minute < 10)tmp += "0";
    tmp += to_string(minute);
    sec %= 60;
    if(sec < 10) tmp += "0";
    tmp += to_string(sec);
    return tmp;
}

int main(){
    cin >> n >> k;
    int limitTime = n * 60 * 60 + 59 * 60 + 59;
    int answer = 0;
    string stringK = to_string(k);
    for(int sec = 0; sec <= limitTime; sec++){
        string stringSec =  getStringSec(sec);
        if(stringSec.find(stringK)!=-1)answer++;
    }
    cout << answer << '\n';
}
