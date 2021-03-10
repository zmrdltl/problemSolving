#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, ans;
int main(){
    cin >> n;
    vector <int> ropeWeight(n);
    for(int i = 0; i < n; i++){
        cin >> ropeWeight[i];
    }
    sort(ropeWeight.begin(),ropeWeight.end());
    for(int i = 0; i < ropeWeight.size(); i++){
        ans = max(ans,ropeWeight[n-i-1]*(i+1));
    }
    cout << ans <<'\n';
}