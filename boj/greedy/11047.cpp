#include <iostream>
using namespace std;
int n, k;
int coin[10];
int sum;
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> coin[i];
    for(int i = n-1; i >= 0; i--){
        sum += k / coin[i];
        k %= coin[i];
    }
    cout << sum << '\n';
}