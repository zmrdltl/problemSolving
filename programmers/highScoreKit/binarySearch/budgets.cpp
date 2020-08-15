#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int solution(vector<int> budgets, int M) {
    ll answer = -1;
    ll l=1,r=M;
    ll sum = 0;
    int m = 0;
    for(auto &i : budgets){sum+= i; m = max(m,i);}
    if(sum<=M) return m; //상한가가 그냥 가장 높은 예산 차지하는 거면 바로 가장 높은 예산 리턴

    while(l<=r){
        //상한선
        ll mid = (r+l)/2;
        sum= 0;
        for(int i = 0 ; i < budgets.size(); i++){
            if(mid <= budgets[i]) sum += mid; //넘거나 같으면 그냥 상한가
            else sum += budgets[i]; //넘지 않으면 요청액 그대로 배정         
        }
        //cout << l << ' '<< mid << ' ' << r <<  ' ' << sum << '\n';
        //상한가 줄여야
        if(sum > M) r = mid-1;
        //상한가 늘려야
        else if(sum <= M){l = mid+1; answer = max(answer,mid);}
    }
    return answer;
}

int main(){
    //vector <int> budgets({120,110,140,150});
    vector <int> budgets({1,2,3,4,5,6,7,8,9,10});
    int M = 56;
    cout << solution(budgets,M);
}