#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i = 0; i < arr1.size(); i++){
        for(int j = 0; j < arr1[i].size(); j++){
            for(int k = 0; k < arr2.size(); k++){
                arr1[j][k] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return arr1;
}