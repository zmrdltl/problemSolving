#include <bits/stdc++.h>
using namespace std;
int usePlan, leftLiter, availableLiter;
int main(){
    cin >> usePlan >> leftLiter;
    availableLiter = 60 + leftLiter;
    if(usePlan <= availableLiter) cout << usePlan * 1500;
    else cout << availableLiter * 1500 + (usePlan - availableLiter) * 3000;
}