#include <bits/stdc++.h>
#define pi 3.14159265359
using namespace std;
int k;

int main(){
    cin >> k;
    for(int i = 1; i <= k; i++){
        double balloonNum, weight, radius, totalHelium = 0;
        cin >> balloonNum >> weight;
        for(int j = 1; j <= balloonNum; j++){
            cin >> radius;
            totalHelium += 4.0 / 3.0 * pi * pow(radius, 3) / 1000;
        }
        printf("Data Set %d:\n", i);
        if(totalHelium >= weight) cout << "Yes";
        else cout << "No";
        printf("\n\n");
    }
}