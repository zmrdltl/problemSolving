#include <iostream> 
using namespace std;
int b, w, maxSide;
bool canMakeSquare = false; 
int main(void) { 
    cin >> b >> w; 
    for (int side = 1; ; side++) { 
        int half = (side * side) / 2; 
        int otherHalf = (side * side) - half; 
        if ((b >= half && w >= otherHalf) || (w >= half && b >= otherHalf)) { 
            canMakeSquare = true; maxSide = side; 
        } 
        else break;
    } 
    if (canMakeSquare == false) cout << "Impossible\n"; 
    else cout << maxSide;
}