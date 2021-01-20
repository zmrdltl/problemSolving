#include <bits/stdc++.h>
using namespace std;
int main(){
    int cnt = 1;
    while(1){
        double x;
        cin>> x;
        if(x == 0) break;
        double y,z;
        cin >> y >> z;
        if(x >= sqrt(z/2 * z/2 + y/2*y/2) ){
            cout << "Pizza "<< cnt << " fits on the table.\n";
        }else {
            cout << "Pizza "<< cnt << " does not fit on the table.\n";
        }
        cnt++;
    }
}