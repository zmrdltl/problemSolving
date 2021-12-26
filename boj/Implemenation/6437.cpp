#include <bits/stdc++.h>
using namespace std;
int p, s, cnt;

string getName(){
    int diff = p - s;
    if(diff == 1) return "Birdie.\n";
    if(diff == -1) return "Bogey.\n";
    if(diff == 2 && s == 1) return "Hole-in-one.\n";
    if(diff == 2) return "Eagle.\n";
    if(diff == 3) return "Double eagle.\n";
    if(diff == 0) return "Par.\n";
    return "Double Bogey.\n";
}

int main(){
    while(1){
        cnt++;
        cin >> p >> s;
        if(!p && !s) break;
        printf("Hole #%d\n", cnt);
        cout << getName() << '\n';
    }
}