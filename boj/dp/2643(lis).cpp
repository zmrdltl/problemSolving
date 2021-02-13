#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
vector <pii> paper;
int paperNum;
int d[101];
int main(){
    cin >> paperNum;
    for(int i = 0; i < paperNum; i++){
        int x,y;
        cin >> x >> y;
        paper.emplace_back(min(x,y),max(x,y));
    }
    sort(paper.begin(),paper.end());
    int ans = 1;
    for(int i = 0; i < paperNum; i ++){
        d[i] = 1;
        auto[x,y] = paper[i];
        for(int j = 0; j < i; j++){
            auto[nx,ny] = paper[j];
            if(x >= nx && y >= ny){
                d[i] = max(d[i],d[j]+1);
            }
        }
        ans = max(ans,d[i]);

    }
    cout << ans <<'\n';
}