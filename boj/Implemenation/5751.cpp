#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    while(1){
        int johnWin = 0, maryWin = 0;
        cin >> n;
        if(!n) break;
        for(int i = 0, x; i < n; i++){
            cin >> x;
            if(!x) maryWin++;
            else johnWin++;
        }
        printf("Mary won %d times and John won %d times\n", maryWin, johnWin);
    }
}