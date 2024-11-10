#include <bits/stdc++.h>
using namespace std;

string solution(int n) {
    string answer = "";
    int num = n;
    while(num){
        if(num % 3 == 0) answer = "4" + answer, num--;
        else if(num%3==1) answer = "1" + answer;
        else if(num%3==2) answer = "2" + answer;
        num/=3;
    }
    return answer;
}

int main(){
    int n;
    cin >> n;
    cout << solution(n);
}