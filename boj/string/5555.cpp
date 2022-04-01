#include <bits/stdc++.h>
using namespace std;
string stringToFind, ringString;
int n, cnt;
int main(){
    cin >> stringToFind;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> ringString;
        ringString += ringString;
        if(ringString.find(stringToFind) != string::npos) cnt++;
    }
    cout << cnt;
}