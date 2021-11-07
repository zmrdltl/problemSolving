#include <bits/stdc++.h>
using namespace std;
double w,h,diagonalCut,rectangleCut;
int main(){
    cin >> w >> h;
    rectangleCut = w + h;
    diagonalCut = sqrt(w*w + h*h);
    printf("%.9f", rectangleCut - diagonalCut);
}