#include <bits/stdc++.h>
using namespace std;
int n;
vector <string> serial;
bool cmp(string a, string b){
    if(a.size() == b.size()){
        int sumA = 0,sumB = 0;
        for(int i = 0; i < a.size(); i++){
            if('1'<=a[i]&&a[i]<='9') sumA += a[i] - '0';
            if('1'<=b[i]&&b[i]<='9') sumB += b[i] - '0';
        }
        if(sumA == sumB) return a < b;
        return sumA < sumB;
    }
    return a.size() < b.size();
}
int main(){
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        serial.push_back(s);
    }
    sort(serial.begin(),serial.end(),cmp);
    for(auto s:serial) cout << s << '\n';
}