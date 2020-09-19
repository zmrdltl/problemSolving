#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s;
int oneArea;
int zeroArea;
int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        int j = i;
        if(s[i]=='0') zeroArea++;
        else oneArea++;
        while(s[i]==s[j++]);
        i = j-2;
    }
    cout << min(zeroArea, oneArea) <<'\n';
}