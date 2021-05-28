#include <bits/stdc++.h>
using namespace std;
int t, ck[1300001];
vector <int> prime;

void checkPrime(){
    for(int i = 2; i <= 1300000; i++){
        if(ck[i]) continue;
        for(int j = i+i; j <= 1300000; j+=i) ck[j] = 1;
    }
}

void makePrime(){
    for(int i = 2; i <= 1300000; i++){
        if(!ck[i]) prime.push_back(i);
    }
}

int binarySearch(int key){
    int l = 2;
    int r = prime.size() - 1;
    while(l<=r){
        int mid = (l+r) / 2;
        if(prime[mid] >= key) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}

int main(){
    cin >> t;
    checkPrime();
    makePrime();
    while(t--){
        int k;
        cin >> k;
        if(!ck[k]) cout << 0 << '\n';
        else {
            int idx = binarySearch(k);
            cout << prime[idx] - prime[idx-1] << '\n';
        }
    }
}