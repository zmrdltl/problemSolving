#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[1000];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int ans = 0;
    int sum = 0;
    for(int i = 0; i < n; i ++){
        sum += arr[i];
        ans += sum;
    }
    cout << ans << '\n';
}