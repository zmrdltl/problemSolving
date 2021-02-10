#include <bits/stdc++.h>
using namespace std;

int getIntFront(string front){
    int sum = 0;
    for(int i = 0; i < front.size(); i++)
        sum += (front[i]-'A') * pow(26,front.size()-i-1);
    return sum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string front = s.substr(0,3);
        string back = s.substr(4,4);
        if(abs(getIntFront(front) - stoi(back)) <= 100){
            cout << "nice\n";
        }else{
            cout << "not nice\n";
        }
    }
}