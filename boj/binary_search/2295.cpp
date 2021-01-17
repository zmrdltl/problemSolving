#include<bits/stdc++.h>
#define MAX 1010
using namespace std;
int arr[MAX], arr2[MAX*MAX], cnt, N;
int main()
{
    int i, j;
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr + 1, arr + 1 + N);
    for (i = 1; i <= N; i++)
    {
        for (j = i; j <= N; j++)
        {
            arr2[++cnt] = arr[i] + arr[j];
        }
    }
    sort(arr2 + 1, arr2 + 1 + cnt);
    for (i = N; i >= 1; i--)
    {
        for (j = i; j >= 1; j--)
        {
            if (binary_search(arr2 + 1, arr2 + cnt + 1, arr[i] - arr[j]))
            {
                printf("%d", arr[i]);
                break;
            }
        }
        if (j != 0)
        {
            break;
        }
    }
    return 0;
}