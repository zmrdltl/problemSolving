#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
ll liquid[5001];
ll answerArr[3];
int n;
void twoPointer(){
    ll result =  3e9;
    for(int first = 0; first < n - 2; first++){
        ll left = first+1;
        ll right = n-1;
        while(left < right){
            ll sum = liquid[left] + liquid[right] + liquid[first];
            if(abs(result) > abs(sum)){
                result = sum;
                answerArr[0] = liquid[first];
                answerArr[1] = liquid[left];
                answerArr[2] = liquid[right];
            }
            if(sum>=0) right--;
            else left++;
        }   
    }
    sort(answerArr,answerArr+3);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> liquid[i];
    sort(liquid,liquid+n);
    twoPointer();
    for(int i = 0; i < 3; i++) cout << answerArr[i] << ' ';
}