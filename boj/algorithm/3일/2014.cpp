#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll k, n;
priority_queue <ll, vector<ll>, greater<ll> > minHeap;
vector <ll> primes, candidates;

int main(){
    cin >> k >> n;
    for(int i = 0; i < k; i++){
        ll x;
        cin >> x;
        primes.push_back(x);
        minHeap.push(x);
    }
    ll head = 0;
    for(int i = 0; i < n; i++){
        head = minHeap.top();
        minHeap.pop();
        for(int j = 0; j < k; j++){
            minHeap.push(head * primes[j]);
            if(head % primes[j] == 0) break;
        }
    }
    cout << head;
}