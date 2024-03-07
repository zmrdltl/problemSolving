class Solution {
public:
    int getSumDigits(int i){
        int sum = 0;
        string s = to_string(i);
        for(auto c : s) {
            sum += c - '0';
        }
        return sum;
    }

    int countLargestGroup(int n) {
        map <int, int> groupMap;
        int ans = 0, largestGroupNum = 0;
        for(int i = 1; i <= n; i++) {
            int sumDigits = getSumDigits(i);
            groupMap[sumDigits]++;
            largestGroupNum = max(largestGroupNum, groupMap[sumDigits]);
        }
        for(auto g : groupMap) {
            if (largestGroupNum == g.second) {
                ans++;
            }
        }
        return ans;
    }
};