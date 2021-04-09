#include <bits/stdc++.h>
using namespace std;
long long n,a,b,c;
char op,eq;
int main(){
    cin >> n;
    while(n--){
        int flag = 0;
        cin >> a >> op >> b >> eq >> c;
        if(op=='*'){
            if(a*b==c) flag = 1;
        }else if(op=='+'){
            if(a+b==c)flag=1;
        }else if(op=='-'){
            if(a-b==c)flag=1;
        }else if(op=='/'){
            if(!b || a/b==c)flag=1;
        }
        if(flag)cout << "correct\n";
        else cout << "wrong answer\n";
    }
}