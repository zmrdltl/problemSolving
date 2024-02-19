#include <bits/stdc++.h>
class Solution {
public:
    vector <int> split(string input, char delimeter){
        vector <int> splited;
        stringstream ss(input);
        string tmp;
        while(getline(ss, tmp, delimeter)) {
            splited.push_back(stoi(tmp));
        }
        return splited;
    }
    int daysBetweenDates(string date1, string date2) {
        vector <string> dates = {date1, date2};
        sort(dates.begin(), dates.end());

        vector <int> yearMonthDay1 = split(dates[0], '-');
        vector <int> yearMonthDay2 = split(dates[1], '-');

        chrono::year_month_day ymd1{chrono::year(yearMonthDay1[0]),
                                    chrono::month(yearMonthDay1[1]),
                                    chrono::day(yearMonthDay1[2])};
        chrono::year_month_day ymd2{chrono::year(yearMonthDay2[0]),
                                    chrono::month(yearMonthDay2[1]),
                                    chrono::day(yearMonthDay2[2])};

        auto tp1 = chrono::sys_days{ymd1};
        auto tp2 = chrono::sys_days{ymd2};

        return (tp2 - tp1).count();
    }
};