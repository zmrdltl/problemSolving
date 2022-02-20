#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int main(){
    int t, n;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        double ans, height, width;
        double maxX = -INF, maxY = -INF, minX = INF, minY = INF;

        for(int i = 0; i < n; i++){
            double x,y;
            cin >> x >> y;
            maxX = max(maxX, x);
            maxY = max(maxY, y);
            minX = min(minX, x);
            minY = min(minY, y);
        }

        height = maxY - minY;
        width = maxX - minX;

        printf(
            "Case %d: Area %f, Perimeter %f\n", 
            i, 
            height * width,
            height * 2 + width * 2
        );
    }
}