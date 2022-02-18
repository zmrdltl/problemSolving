#include <bits/stdc++.h>
using namespace std;
int z, n;
char answers[4] = {'A', 'B', 'C', 'D'};

int main(){
    cin >> z;
    while(z--){
        cin >> n;
        int moved = (n-1) / 3;
        int movedLeft = (n-1) % 3;
        cout << answers[((moved % 4) + movedLeft) % 4] << '\n';
    }
}