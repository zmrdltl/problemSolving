#include <bits/stdc++.h>
#define ll long long
using namespace std;
int triangleNum[1001];
int t;

bool ck(int num){
    for(int i = 1; i <=50; i++)
        for(int j = 1; j <=50; j++)
            for(int k = 1; k <= 50; k++)
                if(triangleNum[i] + triangleNum[j] + triangleNum[k] == num)
                    return true;            
    return false;
}

int main(){
    for(int i = 1; i <= 1000; i++) triangleNum[i] = triangleNum[i-1] + i;

    cin >> t;
    while(t--){
        int num;
        cin >> num;
        cout << ck(num) <<'\n';
    }
}