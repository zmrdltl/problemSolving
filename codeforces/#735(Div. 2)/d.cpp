#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using pii = pair<int,int>;
int t;
ll a[100001];
vector <pii> v;

int main(){
    fastio;
    cin >> t;
    while(t--){
        string s;
        int n, alpha[26] = {0}, cnt=0;
        cin >> n;

        for(int i = 0; i < n; i++){
            alpha[cnt]++;
            cnt = (cnt + 1) % 26;
        }
        for(int i = 0; i < 26; i++){
            while(alpha[i]--){
                s += i + 'a';
            }
        }
        cout << s << '\n';
    }
}