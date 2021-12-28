#include <bits/stdc++.h>
#define PI 3.14159265359
#define COVER_AREA 50
using namespace std;
int main(){
    while(1){
        int hour = 0;
        double a, b, propertyArea;
        cin >> a >> b;
        if(!a && !b) break;
        propertyArea = (a * a + b * b) * PI / 2;
        hour = ceil(propertyArea / COVER_AREA);
        cout << "The property will be flooded in hour " <<  hour << ".\n";
    }
}