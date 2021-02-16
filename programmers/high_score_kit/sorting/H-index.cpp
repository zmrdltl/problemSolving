#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size();
    for(int i = 1; i <= 1000; i++){
        int cnt = 0;
        for(int j = 0; j < size; j++){
            if(citations[j] >= i) cnt++;
        }
        if(cnt >= i) answer = i;
    }
    return answer;
}