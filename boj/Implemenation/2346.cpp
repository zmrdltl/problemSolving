#include <bits/stdc++.h>
using namespace std;
int n;
int moveBalloon[1001];
deque <int> balloon;
vector <int> ans;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> moveBalloon[i];
    for(int i = 1; i <= n; i++) balloon.push_back(i);

    for(int i = 0; i < n; i++){
        ans.push_back(balloon.front());
        int moving = moveBalloon[balloon.front()-1] ;
        balloon.pop_front();
        if(moving > 0){
            for(int i = 0; i < moving - 1; i++){
                balloon.push_back(balloon.front());
                balloon.pop_front();
            }
        }else{
            for(int i = 0; i < -moving; i++){
                balloon.push_front(balloon.back());
                balloon.pop_back();
            }
        }
    }
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
}