#include <bits/stdc++.h>
using namespace std;
int cardPerPerson[1000][5], peopleNum;
vector <pair<int,int>> maxCard;
vector <int> cards;
int getMaxCardNum(int curPeople, int depth, int idx, int cardNum){
    if(depth == 3){
        int sum = 0;
        for(int i = 0; i < 3; i++)
            sum += cards[i];
        return max(sum%10,cardNum);
    }
    int maxCardNum = 0;
    for(int i = idx; i < 5; i++){
        cards.push_back(cardPerPerson[curPeople][i]);
        maxCardNum = max(maxCardNum,getMaxCardNum(curPeople, depth+1, i+1, cardNum));
        cards.pop_back();
    }
    return maxCardNum;
}

int main(){
    cin >> peopleNum;
    for(int i = 0; i < peopleNum; i++){
        for(int j = 0; j < 5; j++)
            cin >> cardPerPerson[i][j];
        maxCard.push_back({getMaxCardNum(i,0,0,0) , i + 1});
    }
    sort(maxCard.rbegin(),maxCard.rend());
    cout << maxCard[0].second;
}