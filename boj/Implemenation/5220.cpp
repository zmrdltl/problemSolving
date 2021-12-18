#include <bits/stdc++.h>
using namespace std;
int t;

string bin(int num){
    int tmp = num;
    string binString = "";
    while(tmp){
        binString += to_string(tmp % 2);
        tmp/=2;
    }
    reverse(binString.begin(), binString.end());
    return binString;
}

bool isSame(string binString, int checkBit){
    int cntOne = 0;
    for(auto b : binString)
        if(b == '1') cntOne++;
    if(cntOne % 2) cntOne = 1;
    else cntOne = 0;
    return checkBit == cntOne;
}

int main(){
    cin >> t;
    while(t--){
        int num, checkBit;
        cin >> num >> checkBit;
        string binString = bin(num);
        if(isSame(binString, checkBit)) cout << "Valid\n";
        else cout << "Corrupt\n";
    }
}