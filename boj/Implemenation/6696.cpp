#include <bits/stdc++.h>
#define PI 3.14159265359
#define COVER_AREA 50
using namespace std;
int main(){
    while(1){
        int hour = 0;
        double x, y, propertyArea;
        cin >> x >> y;
        if(!x && !y) break;
        propertyArea = (x * x + y * y) * PI / 2;
        hour = ceil(propertyArea / COVER_AREA);
        cout << "The property will be flooded in hour " <<  hour << ".\n";
    }
}