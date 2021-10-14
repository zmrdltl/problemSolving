#include <bits/stdc++.h>
using namespace std;
double milePerGallon;
int main(){
    cin >> milePerGallon;
    //1 gallon : 3.785411784L
    //1L : 1 / 3.785411784 gallon
    //1 mile : 1609.344m
    //1m : 1000 / 1609344 mile
    //1km : 1000000 / 1609344 mile
    //100km : 100000000 / 1609344 mile
    printf("%.12f", milePerGallon * (1000000.0 / 1609344) / (1.0 / 3.785411784));
}