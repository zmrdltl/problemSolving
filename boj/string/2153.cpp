#include <bits/stdc++.h>
using namespace std;
int num;
bool isPrime(){
    for(int i = 2; i < num; i++)
        if(num % i == 0) return false;
    return true;
}

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if('a' <= s[i] && s[i] <= 'z'){
            num += s[i] - 'a' + 1;
        }else{
            num += s[i] - 'A' + 27;
        }
    }
    if(isPrime()){
        cout << "It is a prime word.";
    }else{
        cout << "It is not a prime word.";
    }
}