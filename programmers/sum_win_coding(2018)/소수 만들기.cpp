#include <vector>
#include <iostream>
using namespace std;

int prime[10000];
int ck[10000];
int threeNums[3];
int answer = 0;

void initPrime(){
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 2; i*i <= 10000; i++){
        for(int j = i+i; j<=10000; j+=i){
            if(!prime[j]) prime[j] = 1;
        }
    }
    
}
bool isPrime(int primeNum){
    if(prime[primeNum]) return 0;
    else return 1;
}

void backtracking(vector <int> &nums,int level,int idx){
    if(level==3){
        int primeNum = 0;
        for(int i = 0; i < 3; i++) primeNum += threeNums[i];
        if(isPrime(primeNum)) 
            answer++;
        return;
    }
    for(int i = idx; i < nums.size(); i++){
        if(!ck[nums[i]]){
            ck[nums[i]] = 1;
            threeNums[level] = nums[i];
            backtracking(nums,level+1,i);
            ck[nums[i]] = 0;
        }
    }
    return;
}

int solution(vector<int> nums) {
    initPrime();
    backtracking(nums,0,0);
    return answer;
}