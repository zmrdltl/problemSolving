#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i = 0; i < arr1.size(); i++){
        for(int j = 0; j < arr1[i].size(); j++){
            vector <int> tmp (arr1[i].size(),0);
            for(int k = 0; k < arr2.size(); k++){
                tmp[i][j] += arr1[i][k] * arr2[k][j];
            }
            answer.push_back(tmp);
        }
    }
    return answer;
}