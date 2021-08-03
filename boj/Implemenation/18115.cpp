#include <bits/stdc++.h>
using namespace std;
int n, op[1000001];
deque <int> cards;

int main(){
    cin >> n;

    int num = 1;
    for(int i = n; i >= 1; i--) cin >> op[i];
    for(int i = 1; i <= n; i++) {

        if(op[i] == 1) {
            cards.push_front(num);
        }

        else if(op[i] == 2){
            int tmp = cards.front();
            cards.pop_front();
            cards.push_front(num);
            cards.push_front(tmp);
        }

        else {
            cards.push_back(num);
        }
        num++;
    }

    for(auto c : cards) cout << c << ' ';
}