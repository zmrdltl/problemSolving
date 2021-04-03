#include <string>
#include <vector>
#include <iostream>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int solution(vector<int> arr) {
    int answer = 1;
    int gc = 0;
    for(auto &a : arr){
        gc = gcd(a,answer);
        answer = answer/gc * a / gc * gc;
        
    }
    return answer;
}