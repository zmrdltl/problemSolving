#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pCnt = 0;
    int yCnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'p' || s[i] =='P') pCnt++;
        else if(s[i] == 'y' || s[i] == 'Y') yCnt++;
    }
    return pCnt == yCnt;
}