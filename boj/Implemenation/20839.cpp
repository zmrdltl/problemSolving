#include <bits/stdc++.h>
using namespace std;
double a, c, e, student[3];

char getGrade(){
    if(student[0] >= a && student[1] >= c && student[2] >= e) return 'A';
    if(student[0] >= a / 2 && student[1] >= c && student[2] >= e) return 'B';
    if(student[1] >= c && student[2] >= e) return 'C';
    if(student[1] >= c / 2 && student[2] >= e / 2) return 'D';
    return 'E';
}

int main(){
    cin >> a >> c >> e;
    for(int i = 0; i < 3; i++) cin >> student[i];
    cout << getGrade();
}