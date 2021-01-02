#include <vector>
#include <algorithm>
using namespace std;
int cnt[200001];
int solution(vector<int> nums)
{
    int answer = 0;
    int size = nums.size();
    int category = 0;
    for(int i = 0; i < size; i++){
        if(!cnt[nums[i]]) category++;
        cnt[nums[i]]++;
    }
    return min(category,size/2);
}