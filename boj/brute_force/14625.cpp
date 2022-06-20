#include <bits/stdc++.h>
using namespace std;
int startHour, startMinute, endHour, endMinute, s, e, num, ans;

string getMinString(int minute){
  string minString;
  string hourStr = to_string(minute/60);
  if(hourStr.size() == 1) minString += "0" + hourStr;
  else minString += hourStr;

  string minuteStr = to_string(minute%60);
  if(minuteStr.size() == 1) minString += "0" + minuteStr;
  else minString += minuteStr;

  return minString;
}

bool isNumExist(string minute){
  for(auto m : minute){
    if(m -'0' == num) return true;
  }
  return false;
}

int main(){
  cin >> startHour >> startMinute >> endHour >> endMinute >> num;
  s = startHour * 60 + startMinute;
  e = endHour * 60 + endMinute;
  for(int i = s; i <= e; i++){
    string curMinute = getMinString(i);
    if(isNumExist(curMinute)) ans++;
  }
  cout << ans;
}