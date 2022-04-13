#include <bits/stdc++.h>
using namespace std;

vector <int> getNotation(int num, int b){
    int tmp = num;
    vector <int> notationB;
    while(tmp){
        notationB.push_back(tmp % b);
        tmp /= b;
    }
    return notationB;
}

bool isPalindrome(vector <int> notationB){
    int sz = notationB.size();
    for(int i = 0; i < sz / 2; i++)
        if(notationB[i] != notationB[sz - i - 1]) 
            return false;
    return true;
}

int main(){
    int t, num;
    cin >> t;
    while(t--){
        cin >> num;
        int isValid = 0;
        for(int b = 2; b <= 64; b++){
            vector <int> notationB = getNotation(num, b);
            if(isPalindrome(notationB)) { isValid = 1; break; }
        }
        cout << isValid << '\n';
    }
}