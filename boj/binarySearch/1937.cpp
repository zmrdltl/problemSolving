#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
vector <int> liquid;
int n;
void twoPointer(int n){
    int left = 0;
    int right = n-1;
    int rightValue, leftValue, sum = 0;
    int result = 0x7f7f7f7f;
    while(left<right){
        sum = (liquid[left] + liquid[right]);
        if(abs(result) > abs(sum)){
            result = sum;
            leftValue = liquid[left];
            rightValue = liquid[right];
        }
        if(sum<=0) left++;
        else right--;
    }
    if(leftValue < rightValue)
        cout << leftValue <<  ' ' <<  rightValue <<'\n'; 
    else
        cout << rightValue  <<  ' ' <<  leftValue <<'\n'; 
}

int main(){
    cin >> n;
    for(int i = 0; i <n; i++){
        int feature;
        cin >> feature;
        liquid.push_back(feature);
    }
    sort(liquid.begin(),liquid.end());
    twoPointer(n);
}

