#include <bits/stdc++.h>
using namespace std;
int m, n;
map <string,int> numMap;
string getString(int num){
    if(num == 0) return "zero";
    if(num == 1) return "one";
    if(num == 2) return "two";
    if(num == 3) return "three";
    if(num == 4) return "four";
    if(num == 5) return "five";
    if(num == 6) return "six";
    if(num == 7) return "seven";
    if(num == 8) return "eight";
    if(num == 9) return "nine";
}

int main(){
    cin >> m >> n;
    for(int i = m; i <= n; i++){
        string s;
        if(i >= 10) s = getString(i / 10) + getString(i % 10);
        else s = getString(i);
        numMap[s] = i;
    }
    int cnt = 0;
    for(auto el : numMap){
        cout << el.second << ' ', cnt++;
        if(cnt % 10 == 0) cout << '\n';
    }
}