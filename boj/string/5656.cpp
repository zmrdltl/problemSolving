#include <bits/stdc++.h>
using namespace std;
int main(){
    string b;
    int a,c;
    int ca = 0;
    while(1){
        ca++;
        cin >> a >> b >> c;
        int flag = 0;
        if(b == "E") break;
        if(b == ">") {
            if(a > c) flag = 1;
        }
        else if(b == ">="){
            if(a >= c) flag = 1;
        }
        else if(b == "<"){
            if(a < c) flag = 1;
        }
        else if(b == "<="){
            if(a <= c) flag = 1;
        }
        else if(b == "=="){
            if(a == c) flag = 1;
        }
        else if(b == "!="){
            if(a != c) flag = 1;
        }

        if(flag){
            printf("Case %d: true\n", ca);
        }else{
            printf("Case %d: false\n", ca);
        }
    }
}