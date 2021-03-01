#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
int n, q;
int z, o;
int main(){
    fastio;
    cin >> n >> q;
    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1) o++;
    }
    while(q--){
        int op,num;
        cin >> op >> num;
        if(op==1){
            if(a[num-1] == 0) o++;
            else o--;
            a[num-1] = 1 - a[num-1];
        }else{
            if(num > o) cout << 0 <<'\n';
            else cout << 1 <<'\n';
        }
    }
}