#include <bits/stdc++.h>
#define ll long long
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        ll l = 1;
        ll r = n-1;
        while(l<=r){
            ll mid = (l+r)/2;
            int res = guess(mid);
            if(res == -1) r = mid - 1;
            else if(res == 1) l = mid + 1;
            else return mid;
        }
        return n;
    }
};