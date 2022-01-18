#include <bits/stdc++.h>
using namespace std;
int allBlock, block, height;
int main(){
    cin >> allBlock;
    while(block <= allBlock) {
        block += 2 * height * height + 2 * height + 1;
        height++;
    }
    cout << height - 1;
}