#include <iostream>
#include <vector>
using namespace std;
vector <int> ans;

bool isPrime(int num){
    for(int i = 2; i*i <= num; i++){
        if(num % i == 0) return 0;
    }
    return 1;
}

void backtracking(int now,int depth,int n){
    if(isPrime(now)){
        if(depth == n){
            ans.push_back(now);
            return;
        }
        for(int i = 1; i < 10; i++){
            backtracking(now*10 + i, depth+1, n);
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 2; i < 10; i++)
        backtracking(i, 1, n);
    for(int i  =0; i < ans.size(); i++){
        cout << ans[i] << '\n';
    }
}