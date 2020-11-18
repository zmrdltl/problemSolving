#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
ll a[100], d[101][101];
ll ans;
int n;
//i까지 뽑았을 때 결과 j를 만드는 경우의 수 d[i][j]
ll topDownDp(int i, int j){
    if(i > n-2 || j < 0 || j > 20) return 0;
    if(i == n-2 && j == a[n-1]) return 1;
    ll &ret = d[i][j];
    if(ret != -1) return ret;
    return ret = topDownDp(i+1,j+a[i+1]) + topDownDp(i+1,j-a[i+1]);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    memset(d,-1,sizeof(d));
    cout << topDownDp(0,a[0]);
}