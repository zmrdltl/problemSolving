#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int a, b, biggest;

int biggestOp(){
    // + - * 순
    int nums[3] = {a+b, a-b, a*b};
    int maxNum = -INF;
    int maxIdx;
    for(int i = 0; i < 3; i++){
        if(maxNum == nums[i]) return -1;
        if(maxNum < nums[i]) 
            maxIdx = i, maxNum = nums[i];
    }
    return maxIdx;
}

string getString(int num){
    string str = to_string(num);
    if(num < 0) return "(" + str + ")";
    return str;
}

int main(){
    cin >> a >> b;
    biggest = biggestOp();
    if(!biggest)          cout << getString(a) << "+" << getString(b) << "=" << getString(a + b);
    else if(biggest == 1) cout << getString(a) << "-" << getString(b) << "=" << getString(a - b);
    else if(biggest == 2) cout << getString(a) << "*" << getString(b) << "=" << getString(a * b);
    else                  cout << "NIE";
}