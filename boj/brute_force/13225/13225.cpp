#include <bits/stdc++.h>
using namespace std;
int n, num;

int main(){
    cin >> n;
    while(n--){
        cin >> num;
        vector <int> divisors;

        for(int i = 1; i <= num; i++) {
            if(num % i == 0) divisors.push_back(i);
        }
        cout << num << ' ' << divisors.size() << '\n';
    }
}