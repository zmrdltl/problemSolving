#include <iostream>
using namespace std;
int stick[100000];
int n;
int answer = 1;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> stick[i];
    int pivot = stick[n-1];
    for(int i = n-2; i >= 0; i--)
        if(stick[i]>pivot) 
            answer++, pivot = stick[i];
    cout << answer <<'\n';
}