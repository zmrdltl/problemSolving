#include <bits/stdc++.h>
using namespace std;
int phoneNum, num;

bool isPrime(int num){
    for(int i = 2; i < num; i++)
        if(num % i == 0) return false;
    return true;
}

int main(){
    cin >> phoneNum >> num;
    string newPhoneNum = to_string(num) + to_string(phoneNum);
    if(isPrime(phoneNum) && isPrime(stoi(newPhoneNum))) cout << "Yes";
    else cout << "No";
}