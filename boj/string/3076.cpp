#include <iostream> 
using namespace std; 
int main(void) { 
    int r, c, a, b; 
    cin >> r >> c >> a >> b; 
    for (int i = 0; i < r; i++) {
        for (int k = 0; k < a; k++) { 
            for (int j = 0; j < c; j++) { 
                if ((i + j) % 2 == 0) 
                    for (int x = 0; x < b; x++) 
                        cout << "X"; 
                else 
                    for (int x = 0; x < b; x++) 
                        cout << "."; 
            } 
            cout << '\n'; 
        } 
    } 
}
