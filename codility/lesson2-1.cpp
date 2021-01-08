#include <vector>
#include <iostream>
#include <deque>
using namespace std;

vector<int> solution(vector<int> &A, int K) {
    deque <int> q;
    vector <int> answer;
    int size = A.size();
    if(size){
        for(int i = 0; i < size; i++) q.push_back(A[i]);
        for(int i = 0; i < K; i++){
            q.push_front(q.back());
            q.pop_back();
        }
        while(!q.empty()){
            answer.push_back(q.front());
            q.pop_front();
        }
    }
    return answer;
}
