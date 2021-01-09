#include  <iostream>
using namespace std;
int arr[6] = {500, 100, 50, 10, 5, 1};
int main(){
    int coin;
    cin >> coin;
    int lef = 1000 - coin;
    int ans = 0;
    for(int i = 0 ; i < 6; i++){
        ans += lef / arr[i];
        lef %= arr[i];
    }
    cout << ans <<'\n';
}