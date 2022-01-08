#include <bits/stdc++.h>
using namespace std;

vector <int> getDiv(int n){
    vector <int> tmp;
    for(int i = 1; i < n; i++) {
        if(n%i == 0) tmp.push_back(i);
    }
    return tmp;
}

int getSum(vector <int> div){
    int sum = 0;
    for(auto d : div) sum += d;
    return sum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, sum;
        cin >> n;
        vector <int> div = getDiv(n);
        sum = getSum(div);
        if(sum > n) cout << n << " is an abundant number.";
        else if(sum == n) cout << n << " is a perfect number.";
        else cout << n << " is a deficient number.";
        cout << '\n' << '\n';
    }
}