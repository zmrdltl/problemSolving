#include <bits/stdc++.h>
using namespace std;
double d, rh, rv;
int main(){
    while(1){
        cin >> d >> rh >> rv;
        if(!d && !rh && !rv) break;
        double w = 16 * d / sqrt(337);
        double h = 9 * w / 16;
        printf("Horizontal DPI: %.2f\n", rh / w);
        printf("Vertical DPI: %.2f\n", rv / h);
    }
}