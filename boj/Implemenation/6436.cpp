#include <bits/stdc++.h>
#define FILE_SIZE 1860000
using namespace std;
int sz, cnt;
int main(){
    while(1){
        cnt++;
        cin >> sz;
        if(!sz) break;
        if(sz % 2) sz = sz/2 + 1;
        else sz/=2;
        sz += sz/2;
        printf("File #%d\n", cnt);
        printf("John needs %d floppies.\n", (sz + FILE_SIZE - 1) / FILE_SIZE);
        cout << '\n';
    }
}