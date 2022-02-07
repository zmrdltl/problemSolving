#include <bits/stdc++.h>
using namespace std;
int t, score;
int main(){
    cin >> t;
    while(t--){
        double p[7];
        score = 0;
        for(int i = 0; i < 7; i++) cin >> p[i];
        score += 9.23076 * pow(26.7 - p[0], 1.835); //100미터 허들
        score += 4.99087 * pow(42.5 - p[3], 1.81); //200미터 달리기
        score += 0.11193 * pow(254 - p[6], 1.88); //800미터 달리기

        score += 1.84523 * pow(p[1] - 75, 1.348); //높이뛰기
        score += 56.0211 * pow(p[2] - 1.5, 1.05); //포환던지기
        score += 0.188807 * pow(p[4] - 210, 1.41); //멀리뛰기
        score += 15.9803 * pow(p[5] - 3.8, 1.04); //창던지기
        cout << score << '\n';
    }
}