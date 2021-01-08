#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define ll long long
using namespace std;

unordered_map <int,int> m;

int solution(vector<int> &A) {
    for(auto p : A){
        m[p]++;
    }
    for(auto p : m){
        if(p.second%2) return p.first;
    }
}
