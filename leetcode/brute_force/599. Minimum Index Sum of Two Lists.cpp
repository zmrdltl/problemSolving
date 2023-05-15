class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int sumOfIndex = 0x3f3f3f3f;
        vector<string> ans;
        for(int i = 0; i < list1.size(); i++) {
            for(int j = 0; j < list2.size(); j++) {
                if(list1[i] == list2[j]) {
                    sumOfIndex = min(sumOfIndex, i + j);
                }
            }
        }

        for(int i = 0; i < list1.size(); i++) {
            for(int j = 0; j < list2.size(); j++) {
                if(list1[i] == list2[j] && i + j == sumOfIndex) {
                    ans.push_back(list1[i]);
                }
            }
        }
        return ans;
    }
};