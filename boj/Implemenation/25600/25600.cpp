#include <bits/stdc++.h>
using namespace std;
int n, a, d, g;
vector <int> scores;
int main(){
    cin >> n;
    scores.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a >> d >> g;
        scores[i] = a * (d + g);
        if(a == d + g) {
            scores[i] *= 2;
        }
    }
    cout << *max_element(scores.begin(), scores.end());
}