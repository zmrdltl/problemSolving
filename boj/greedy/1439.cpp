#include <bits/stdc++.h>
using namespace std;
string s;
int zeroCnt, oneCnt;
int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        int j = i;
        if(s[i] == '1') oneCnt++;
        else zeroCnt++;
        while(s[i] == s[j++]);
        i = j - 2;
    }
    cout << min(zeroCnt,oneCnt);
}