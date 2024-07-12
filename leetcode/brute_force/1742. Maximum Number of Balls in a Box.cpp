class Solution {
public:
    int getSum(int limit) {
        int sum = 0;
        while(limit) {
            sum += limit % 10;
            limit /= 10;
        }
        return sum;
    }

    int countBalls(int lowLimit, int highLimit) {
        map <int,int> ballNumCountMap;
        for(int i = lowLimit; i <= highLimit; i++) {
            int limit = i;
            int sum = getSum(limit);
            ballNumCountMap[sum]++;
        }
        int maxBalls = 0;
        int ballNumber = 0;
        for(auto m : ballNumCountMap) {
            maxBalls = max(maxBalls, m.second);
        }
        return maxBalls;
    }
};