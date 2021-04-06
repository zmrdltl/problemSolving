#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N, K;
    cin >> N >> K;
    vector<char> v(N,'?');
    int idx = 0;
    for (int i = 0; i < K; i++){
        int temp;
        char c;
        cin >> temp >> c;
        temp %= N;
        if (idx - temp < 0)
            idx = (idx - temp) + N;
        else
            idx -= temp;
        if (v[idx] != '?' && v[idx] != c){
            cout << '!';
            return 0;
        }
        v[idx] = c;
    }
    for (int i = 0; i < N; i++)
        for(int j=i+1; j<N; j++)
            if (v[i] != '?' && v[i] == v[j]){
                cout << '!';
                return 0;
            }
    for (int i = 0; i < N; i++)
        cout << v[(i + idx) % N];
}


