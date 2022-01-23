#include <bits/stdc++.h>
using namespace std;
string phoneNum, num;

bool isPrime(int n){
    for(int i = 2; i < n; i++)
        if(n % i == 0) return false;
    return true;
}

int main(){
    cin >> phoneNum >> num;
    if(isPrime(stoi(phoneNum)) && isPrime(stoi(num + phoneNum))) cout << "Yes";
    else cout << "No";
}