#include <bits/stdc++.h>
using namespace std;
int length, h, v, biggestVolume, width[2], height[2];
int main(){
    cin >> length >> h >> v;
    width[0] = v, width[1] = length - v;
    height[0] = h, height[1] = length - h;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            biggestVolume = max(biggestVolume ,width[i] * height[j] * 4);
        }
    }
    cout << biggestVolume;
}