#include <iostream>
#define ll long long
using namespace std;
 
int n;
int a[500000];
int b[500000];
long long result;
 
void merge(int l, int mid, int r)
{
    int i = l;
    int j = mid+1;
    int idx = 0;
    while (i <= mid || j <= r){
        if (i <= mid && (j > r || a[i] <= a[j]))
            b[idx++] = a[i++];
        else{
            b[idx++] = a[j++];
            result += (long long)mid - i + 1;
        }   
    }
 
    for (int i=l; i<=r; i++) a[i] = b[i-l];
}
 
void mergesort(int l, int r){
    if (l < r){
        int mid = (l+r) / 2;
        mergesort(l, mid);
        mergesort(mid+1, r);
        merge(l, mid, r);
    }
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    mergesort(0, n-1);
    cout << result;
}