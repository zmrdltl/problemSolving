#include <bits/stdc++.h>
using namespace std;
int n, f, freq[10];
string curNum;
int main(){
    cin >> n >> f;

    for(int num = 1; num <= n; num++){
        curNum = to_string(num);
        for(auto n : curNum) freq[n-'0']++;
    }

    cout << freq[f];
}