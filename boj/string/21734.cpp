#include <bits/stdc++.h>
using namespace std;
string s;
int getSum(int ascii){
    int tmp = ascii;
    int sum = 0;
    while(tmp){
        sum += tmp%10;
        tmp /= 10;
    }
    return sum;
}

int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        int ascii = s[i];
        int sum = getSum(ascii);
        for(int j = 0; j < sum; j++) cout << s[i];
        cout << '\n';
    }
}