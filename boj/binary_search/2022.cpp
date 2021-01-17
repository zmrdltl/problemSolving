#include <bits/stdc++.h>
using namespace std;

double f(double x,double k,double A){
    return - (A * x / k) + A;
}

int main(){
    double a,b,c;
    cin >> a >> b >> c;
    double l = 0;
    double r = min(a,b);
    for(int i = 0; i < 1000; i++){
        double k = (r+l)/2.0;
        double A = sqrt(a*a - k*k);
        double B = sqrt(b*b - k*k);
        double c0 = k * c / B;
        
        if(f(c0,k,A) > c){
            l = k;
        }else r = k;
    }
    printf("%.3lf",l);
}