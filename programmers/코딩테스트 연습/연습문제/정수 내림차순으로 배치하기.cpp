#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    vector <char> num;
    while(n>0){
        num.push_back(n%10);
        n/=10;
    }
    sort(num.rbegin(),num.rend());
    long long answer = 0;
    for(int i = 0; i < num.size(); i++){
        answer += num[i];
        answer *= 10;
    }
    return answer;
}