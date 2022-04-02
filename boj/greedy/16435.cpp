#include <bits/stdc++.h>
using namespace std;
int snakeBirdLength, n;
vector <int> fruitHeight;
int main(){
    cin >> n >> snakeBirdLength;
    fruitHeight.resize(n);
    for(int i = 0; i < n; i++) cin >> fruitHeight[i];
    sort(fruitHeight.begin(), fruitHeight.end());
    for(auto f : fruitHeight){
        if(snakeBirdLength >= f) {
            snakeBirdLength++;
        }
    }
    cout << snakeBirdLength;
}