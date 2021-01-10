#include <iostream> 
#include <algorithm>
using namespace std; 
int height, width; 

void input() { cin >> height >> width; } 

int solve() { 
    if (height == 1) 
        return 1; 
    else if (height == 2) 
        return min(4, (width + 1) / 2); 
    else { 
        if (width >= 7) 
            return width - 2; 
        else 
            return min(4, width); 
    } 
} 

void printAnswer(int ans) {
    cout << ans << '\n'; 
}

int main() { 
    input(); 
    int ans = solve(); 
    printAnswer(ans); 
    return 0; 
}

