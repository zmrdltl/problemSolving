#include <bits/stdc++.h>
using namespace std;
int t, d, n, s, p;
int main(){
    cin >> t;
    while(t--){
        cin >> d >> n >> s >> p;
        int parallelTime = d + n * p, notParallelTime = n * s;
        if(parallelTime > notParallelTime) cout << "do not parallelize\n";
        else if(parallelTime < notParallelTime) cout << "parallelize\n";
        else cout << "does not matter\n";
    }
}