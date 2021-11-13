#include <bits/stdc++.h>
#define pi 3.14159265359
using namespace std;
double circularArea, radius;
int main(){
    cin >> circularArea;
    radius = sqrt(circularArea / pi);
    printf("%.9f",2 * radius * pi);
}