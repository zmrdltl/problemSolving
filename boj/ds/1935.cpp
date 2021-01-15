#include <bits/stdc++.h>
using namespace std;
string operation;
stack <double> calculator;
map <char,double> m;
int main(){
    int n;
    cin >> n >> operation;
    for(int i = 0; i < n; i ++){
        int value;
        cin >> value;
        m['A'+ i] = value;
    }

    for(int i = 0; i < operation.size(); i++){
        if(isalpha(operation[i])){
            calculator.push(m[operation[i]]);
        }else{
            double a = calculator.top();
            calculator.pop();
            double b = calculator.top();
            calculator.pop();
            switch(operation[i]){
                case '*': calculator.push(b*a); break;
                case '/': calculator.push(b/a); break;
                case '+': calculator.push(b+a); break;
                case '-': calculator.push(b-a); break;
            }
        }
    }
    printf("%.2f",calculator.top());
}
