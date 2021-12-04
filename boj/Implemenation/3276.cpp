#include <bits/stdc++.h>
#define MAX 0x3f3f3f3f
using namespace std;
int pebbles, minCol = MAX, minRow = MAX, minSum = MAX;
int main(){
    cin >> pebbles;
    for(int i = 1; i <= pebbles; i++) {
        int j = pebbles % i == 0 ? pebbles / i : pebbles / i + 1;
        if(i + j < minSum) {
            minSum = i + j;
            minRow = i;
            minCol = j;
        }
    }
    cout << minRow << ' ' << minCol;
}