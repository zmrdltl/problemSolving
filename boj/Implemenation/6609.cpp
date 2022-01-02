#include <bits/stdc++.h>
using namespace std;
int m, p, l, e, r, s, n;
int main(){
    while(cin >> m >> p >> l >> e >> r >> s >> n){
        for(int i = 0; i < n; i++){
            //m마리의 모기는 m*e개 알 낳고 사망
            int larva = m*e;

            //p마리의 번데기 중 s번째만 성충이됨
            int adult = p/s;

            //l마리의 유충 중 r번째만 번데기 됨
            int pupa = l/r;

            m = adult;
            p = pupa;
            l = larva;
        }
        cout << m << '\n';
    }
}