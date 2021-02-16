#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int flag = 0;
    for(int i = 1; i <= 5000; i++){
        for(int j = 1; j<= 5000; j++){
            if(yellow == (i-2) * (j-2) &&
              brown == i*j - (i-2) * (j-2))
                return {max(i,j),min(i,j)};            
        }
    }
}
