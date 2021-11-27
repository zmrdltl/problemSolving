#include <bits/stdc++.h>
#define pi 3.14159265359
using namespace std;
int cnt;
int main(){
    while(1) {
        cnt++;
        double diameter, rotated, sec;
        cin >> diameter >> rotated >> sec;
        if(!rotated) break;
        double moved = diameter / (5280.0 * 12.0)* rotated * pi ;
        printf("Trip #%d: %.2f %.2f\n", cnt, moved, moved / sec * 3600);
    }
}