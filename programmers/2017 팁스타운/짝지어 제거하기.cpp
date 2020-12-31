#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack <int> pairing;
    int size = s.size();

    for(int i = 1; i < size; i++){
        if(!pairing.empty()){
            if(pairing.top()==s[i]){
                pairing.pop();
            }
            else pairing.push(s[i]);    
        }else{
            pairing.push(s[i]);
        }
        
    }
    if(pairing.empty()) return 1;
    return 0;
}