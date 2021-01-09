#include <bits/stdc++.h>
using namespace std;
int n;
vector <pair<int,int>> info;
int main(){
    cin >> n;
    for(int i = 0; i < n; i ++){
        int x, y;
        cin >> x >> y;
        info.push_back({x,y});
    }
    vector <int> rank(n,1);
    for(int i = 0; i < n; i++){
        int weight = info[i].first;
        int height = info[i].second;
        for(int j = 0; j < n; j++){
            int weight2 = info[j].first;
            int height2 = info[j].second;
            if(weight > weight2 && height > height2) rank[j]++;
        }
    }
    for(int i = 0; i < n; i++) cout << rank[i] << ' ';
}