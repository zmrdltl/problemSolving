#include <bits/stdc++.h>
using namespace std;
struct Coord{int x, y; };
int n, ans, ck[51];
Coord building[51];

double getInclination(Coord a, Coord b){
    return double(a.y - b.y) / double(a.x - b.x);
}

int main(){
    cin >> n;
    for(int i = 0,y; i < n; i++) cin >> y, building[i] = {i,y};
    for(int k = 0; k < n; k++){
        int cnt = 0;
        double maxInc = -0x3f3f3f3f;
        for(int i = k+1; i < n; i++)  {
            double inc = getInclination(building[k],building[i]);
            if(inc > maxInc) {
                ck[i]++;
                ck[k]++;
                maxInc = inc;
            }
        }


    }
    for(int i = 0; i < n; i++) ans = max(ans,ck[i]);
    cout << ans;
}