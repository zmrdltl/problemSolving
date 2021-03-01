#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
#define ft first
#define sd second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vs = vector<string>;
using vd = vector<double>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vvi = vector<vi>;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,u,v;
        cin >> n >> u >> v;
        vi a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int f = 0;
        int diff = 0;
        for(int i = 0; i < n-1; i++){
            if(a[i]!=a[i+1]) {
                diff = max(diff,abs(a[i+1] - a[i]));
                f = 1;
            }
        }
        if(diff >= 2) cout << 0 <<'\n';
        else{
            if(!f) cout << min(u+v,v+v) <<'\n';
            else cout << min(u,v) <<'\n';
        }
    }
}