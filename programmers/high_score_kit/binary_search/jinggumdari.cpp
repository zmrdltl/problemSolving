#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
 
int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    //바위를 없앨 거리를 이분탐색으로 돌린다.
    int l = 0;
    int r = distance;

    while(l<=r){
        int mid = (l+r)/2; //바위 사이의 거리 적당히 떨어진 바위 사이의 거리들 중 최대값을 찾는다.
        int removeIdx = -1;
        int removeCount = 0;
        for(int i = 0 ; i<=rocks.size(); i++){
            // int d = i==0? rocks[i]:
            // i==rocks.size() ? distance - rocks[rocks.size()-1] : rocks[i]-rocks[removeIdx];
            int d;
            if(i==0){ //돌의 처음
                d = rocks[i];
            }else{
                //돌의 끝.
                if(i == rocks.size()) d = distance - rocks[rocks.size()-1];
                //돌의 중간
                else d = rocks[i] - rocks[removeIdx];
            }
            //지울 조건에 충족 : mid보다 바위간 거리가 작을 때 지운다.
            if(d<mid) removeCount++;
            else removeIdx = i;
        }
        //너무 많이 지웠다. -> 거리를 좀 줄이자
        if(removeCount>n){
            r = mid-1;

        }
        //너무 돌을 덜 제거했다. -> 거리를 좀 늘리자.
        else if(removeCount<=n){
            l = mid+1;
            answer = max(answer,mid);
        }
    }

    return answer;
}
// int main(){
//   int n = 2;
//   vector <int> rocks({2,14,11,21,17})  ;
//   int distance  =25;
//   cout << solution(distance,rocks,n);
// }