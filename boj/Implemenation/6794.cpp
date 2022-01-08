#include <iostream>
using namespace std; 
bool check[6]; 
int n, cnt;
int main() { 
    cin >> n; 
    for (int i = 0; i <= 5; i++)
        for (int j = 0; j <= 5; j++)
            if (i + j == n) check[i] = true; 
    for (int i = 0; i <= n/2; i++)
        if(check[i]) cnt++;
    cout << cnt;
}