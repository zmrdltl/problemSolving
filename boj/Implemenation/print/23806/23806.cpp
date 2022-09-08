#include <bits/stdc++.h>
using namespace std;
int n;

void printEdge(){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n * 5; j++) {
            cout << "@";
        }
        cout << '\n';
    }
}

void printMid(){
    for(int i = 0; i < n * 3; i++) {
        for(int j = 0; j < n; j++) {
            cout << "@";
        }
        for(int j = 0; j < n * 3; j++) {
            cout << " ";
        }
        for(int j = 0; j < n; j++) {
            cout << "@";
        }
        cout << '\n';
    }
}

int main(){
    cin >> n;
    printEdge();
    printMid();
    printEdge();
}
