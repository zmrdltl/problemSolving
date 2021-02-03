#include <iostream>
#define ll long long
using namespace std;
int n;
ll d[1000001] = {0,1,2,};
int main(){
    cin >> n;
    for(int i = 3; i <= n; i++)
        d[i] = (d[i-1] + d[i-2]) % 15746;
    cout << d[n] << '\n';
}