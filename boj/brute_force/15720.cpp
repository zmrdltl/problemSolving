#include <bits/stdc++.h>
#define MAX 0x3f3f3f3f
using namespace std;

int burgerNum, sideNum, drinkNum, totalPrice, minPrice, range;
vector <int> burger, side, drink;

int getSaledPrice(){
  int price = 0;
  for(int i = 0; i < 1000; i++){
    if(i >= burgerNum || i >= sideNum || i >= drinkNum) break;
    price += (burger[i] + side[i] + drink[i]) * 9 / 10;
    range++;
  }
  return price;
}

int getPriceWithRange(vector <int> &menu){
  int price = 0;
  for(int i = range; i < menu.size(); i++){
    price += menu[i];
  }
  return price;
}

int getOtherPrice(){
  int price = 0;
  price += getPriceWithRange(burger);
  price += getPriceWithRange(side);
  price += getPriceWithRange(drink);
  return price;
}

void setMenuList(vector <int> &menu, int menuNum){
  menu.resize(menuNum);
  for(int i = 0; i < menuNum; i++){
    cin >> menu[i];
    totalPrice += menu[i];
  }
  sort(menu.rbegin(), menu.rend());
}

int main(){
  cin >> burgerNum >> sideNum >> drinkNum;
  setMenuList(burger, burgerNum);
  setMenuList(side, sideNum);
  setMenuList(drink, drinkNum);
  minPrice += getSaledPrice();
  minPrice += getOtherPrice();
  cout << totalPrice << '\n' << minPrice;
}