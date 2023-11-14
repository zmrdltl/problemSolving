class Solution {
    int dayPerMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    int dayPerMonthLeap[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        int isLeap = (year % 400 == 0) || ((year % 4 == 0) && (year % 100) != 0); 
        int ans = day;
        for(int i = 1; i < month; i++) {
            ans += isLeap ? dayPerMonthLeap[i] : dayPerMonth[i];
        }
        return ans;
    }
};