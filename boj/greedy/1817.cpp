#include <bits/stdc++.h>
using namespace std;

int bookNum, maxWeight, answer, sum;
vector <int> booksWeight;

int main(){
  cin >> bookNum >> maxWeight;
  booksWeight.resize(bookNum);

  for(int i = 0; i < bookNum; i++){
    cin >> booksWeight[i];
  }

  for(int i = 0; i < booksWeight.size(); i++){
    int pivot = i, sum = 0;
    while(1){
      sum += booksWeight[pivot];
      if(sum > maxWeight) {
        pivot--; 
        break;
      }
      pivot++;
    }
    i = pivot;
    answer++;
  }
  cout << answer;
}