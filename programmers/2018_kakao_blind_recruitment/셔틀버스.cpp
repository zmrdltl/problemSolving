#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector <int> getIntTime(vector<string> &timetable){
    vector <int> timeInt;
    for(int i = 0; i < timetable.size(); i++){
        int hour = stoi(timetable[i].substr(0,2));
        int minute = stoi(timetable[i].substr(3,2));
        int totalMinute = hour * 60 + minute;
        timeInt.push_back(totalMinute);
    }
    return timeInt;
}

string getTimeString(int time){
    string tmp = "";
    int hour = time / 60;
    int minute = time % 60;
    if(hour < 10) tmp += "0";
    tmp += to_string(hour) + ":" ;
    if(minute < 10) tmp += "0";
    tmp += to_string(minute);
    return tmp;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int pivot = 0, cnt =0;
    vector <int> timeInt = getIntTime(timetable);
    sort(timeInt.begin(),timeInt.end());

    for(int busTime = 0; busTime < n * t; busTime += t){
        int shuttleTime = 9 * 60 + busTime;
        for(cnt = 0; pivot + cnt < timeInt.size() && cnt < m; cnt++){ 
            if(timeInt[pivot + cnt] > shuttleTime) break; 
        }
        pivot += cnt; 
    }
    if(cnt < m) answer = getTimeString(9 * 60 + (n-1) * t);
    else answer = getTimeString(timeInt[pivot-1] - 1);
    return answer;
}

int main(){
    vector<string> t = {"09:00", "09:00", "09:00", "09:00"};
    cout << "정답이 뭐에요? " << solution(2,1,2,t);
}