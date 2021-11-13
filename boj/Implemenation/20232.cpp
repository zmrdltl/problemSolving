#include <bits/stdc++.h>
using namespace std;

string getContestName(int year){
    if( year == 1996 || year == 1997 || year == 2000 || 
        year == 2007 || year == 2008 || year == 2013 || year == 2018
    ) return "SPbSU";
    if( year == 2006) return "PetrSU, ITMO";
    return "ITMO";
}

int main(){
    int year;
    cin >> year;
    cout << getContestName(year);
}