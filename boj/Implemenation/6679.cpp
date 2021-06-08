#include <iostream> 
using namespace std;
 
int calc(int num, int base){
    int ret = 0;
    while (num) ret += num % base, num /= base;
    return ret;
}
 
int main(){
    for (int i = 1000; i < 10000; ++i){
        int dec = calc(i, 10);
        if (dec == calc(i, 12) && dec == calc(i, 16))
            cout << i << '\n';
    }
}
 