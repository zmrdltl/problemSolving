#include <bits/stdc++.h>
using namespace std;
int t;

int convert(int ti){
    int tmp = ti;
    if(ti < 0) tmp = ti + 2400;
    if(ti >= 2400) tmp = ti - 2400;
    if(tmp % 100 >= 60) tmp = 100 * (tmp / 100 + 1) + tmp % 100 - 60;
    if(tmp >= 2400) tmp -= 2400;
    return tmp;
}

int main(){
    cin >> t;
    cout << t << " in Ottawa\n";
    cout << convert(t - 300) << " in Victoria\n";
    cout << convert(t - 200) << " in Edmonton\n";
    cout << convert(t - 100) << " in Winnipeg\n";
    cout << t << " in Toronto\n";
    cout << convert(t + 100) << " in Halifax\n";
    cout << convert(t + 130) << " in St. John's";
}