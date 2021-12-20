#include <bits/stdc++.h>
using namespace std; 
int main() { 
    int n, k; 
    cin >> n >> k; 
    for (int i = 0; i < k; i++) { 
        int s, t, r; 
        cin >> s >> t >> r; 
        int readPage = s * t; 
        int totalReadPage = 0; 
        int totalTime = 0; 
        while (1) { 
            if (n - totalReadPage <= readPage) { 
                totalTime += ceil(double(n - totalReadPage) / s); 
                break; 
            }
            totalReadPage += readPage; 
            totalTime += t + r; 
        } 
        cout << totalTime << "\n"; 
    } 
}
