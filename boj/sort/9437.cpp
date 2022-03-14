#include <bits/stdc++.h>
using namespace std;

int n, cnt[101], allGived = 3;
vector<vector<int>> v;

bool cmp(vector<int> &a, vector<int> &b){
    return a[2] > b[2];
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int countryNum, studentNum, score;
        cin >> countryNum >> studentNum >> score;
        v.push_back({countryNum, studentNum, score});
        cnt[i] = 2;
    }
    sort(v.begin(), v.end(), cmp);
    for(auto e : v) {
        if(!allGived) break;
        if(cnt[e[0]] > 0){
            cout << e[0] << ' ' << e[1] << '\n';
            cnt[e[0]]--, allGived--;
        }
    }
}