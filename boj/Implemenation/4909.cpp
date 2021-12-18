#include <bits/stdc++.h>
using namespace std;

int grades[6];

bool isAllZero(){
    for(int i = 0; i < 6; i++)
        if(grades[i]) return false;
    return true;
}

int main(){
    while(1){
        for(int i = 0; i < 6; i++) cin >> grades[i];
        if(isAllZero()) break;
        sort(grades, grades + 6);
        double sum = 0;
        for(int i = 1; i < 5; i++) sum += grades[i];
        cout << sum / 4 << '\n';
    }
}