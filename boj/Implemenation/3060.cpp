#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t, dayFeedAmount, day;
vector <ll> feed(6), prev(6);

int main(){
    cin >> t;
    while(t--){
        cin >> dayFeedAmount;
        feed.resize(6);
        day = 0;
        int sum = 0;

        for(int i = 0; i < 6; i++) cin >> feed[i];
        vector <int > prev;
        while(1){
            day++;
            for(int i = 0; i < 6; i++){

                int s = i;
                if(i < 3) s+=3;
                else s-=3;
                cout << "i, feed : " << i << ' ' << feed[(i+5)%6] + feed[(i+1)%6] + feed[s] << '\n';
                prev.push_back(feed[(i+5)%6] + feed[(i+1)%6] + feed[s]);
                sum += feed[(i+5)%6] + feed[(i+1)%6] + feed[s];
                if(sum > dayFeedAmount) {break;}
            }
            if(prev.size() < 6) break;
            for(int i = 0; i < 6; i++){
                feed[i] = prev[i];
            }
            cout << "sum : " << sum << '\n';
        }

        cout << day << '\n';

    }
}