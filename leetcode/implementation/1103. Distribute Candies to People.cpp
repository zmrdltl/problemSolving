class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector <int> ans(num_people, 0);
        int cnt = 1;
        while(candies>=0) {
            for(int i = 0; i < num_people; i++) {
                if(candies < cnt) {
                    ans[i] += candies;
                    candies -= cnt;
                    break;
                }
                ans[i] += cnt;
                candies -= cnt;
                cnt++;
            }
        }
        return ans;
    }
};