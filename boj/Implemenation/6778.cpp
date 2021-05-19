#include <bits/stdc++.h>
using namespace std;
int ck[3];
int main(){
    int a,b;
    cin >> a >> b;
    if(a <= 2){
        if(b >= 2){
            ck[1] = 1; 
        }
        if(b<=3){
            ck[2] = 1;
        }
    }
    else{
        if(a >=3 && b<=4) {
            ck[0] = 1;
        }
        if(a <= 6 && b >= 2){
            ck[1] = 1;
        }
    }
    for(int i = 0; i < 3; i++){
        if(ck[i]){
            if(i==0){
                cout << "TroyMartian\n";
            }
            else if(i==1){
                cout << "VladSaturnian\n";
            }
            else{
                cout << "GraemeMercurian\n";
            }
        }
    }
}
