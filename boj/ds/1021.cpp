#include <bits/stdc++.h>
using namespace std;

deque <int> dq;
int n, m, ans;


void moveLeft(){
    dq.push_back(dq.front());
    dq.pop_front();
}

void moveRight(){
    dq.push_front(dq.back());
    dq.pop_back();
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <=n; i++) dq.push_back(i);
    while(m--){
        int x;
        cin >> x;

        int rightMove = 0;
        int leftMove = 0;

        while(dq.front()!=x){
            moveRight();
            rightMove++;
        }
        
        for(int i = 0; i < rightMove; i++) moveLeft();

        while(dq.front()!=x){
            moveLeft();
            leftMove++;
        }

        for(int i = 0; i < leftMove; i++) moveRight();

        if(rightMove < leftMove){
            ans += rightMove;
            while(dq.front()!=x) moveRight();
        }
        else{
            ans += leftMove;
            while(dq.front()!=x) moveLeft();
        }

        dq.pop_front();
    }
    cout << ans << '\n';
}