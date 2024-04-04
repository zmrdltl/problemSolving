class Solution {
public:
    double average(vector<int>& salary) {
        double sumOfExcluded = 0;

        sort(salary.begin(), salary.end());
        for(int i = 1; i < salary.size() - 1; i++) {
            sumOfExcluded += salary[i];
        }

        return sumOfExcluded / (salary.size() - 2);
    }
};