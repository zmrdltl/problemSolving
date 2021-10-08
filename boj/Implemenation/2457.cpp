#include <bits/stdc++.h>
 
#define MAX 100001
 
using namespace std;
 
int N;
int startMonth[MAX], startDay[MAX];
int endMonth[MAX], endDay[MAX];
int end_month, end_day;
int mon, day;
int cnt;
 
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> startMonth[i] >> startDay[i] >> endMonth[i] >> endDay[i];
    }
    end_month = 3;
    end_day = 1;
    mon = 3;
    day = 1;
    while (1){
        if (mon >= 11)
            if (mon != 11 || day == 31)
                break;
        for (int i = 0; i < N; i++)
            if (startMonth[i] <= mon)
                if (startMonth[i] != mon || startDay[i] <= day)
                    if (end_month <= endMonth[i])
                        if (end_month != endMonth[i] || end_day <= endDay[i]) {
                            end_month = endMonth[i];
                            end_day = endDay[i];
                        }
        if (mon == end_month && day == end_day) {
            cnt = 0;
            break;
        }
        mon = end_month;
        day = end_day;
        cnt++;
    }
 
    cout << cnt;
}
