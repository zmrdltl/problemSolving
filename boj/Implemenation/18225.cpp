//1007¹ø ¼Ò½º
#include <bits/stdc++.h>
#define MAX 9111111111111111111
            
using namespace std;
int a[20]; 
double temp, ans;
int x[20], y[20]; 
int sum_x, sum_y; 
int T, N, R; 

void combination(int N, int R, int q) // N : Á¡ °¹¼ö, R : Á¡ °¹¼öÀÇ ¹İÆ´(N/2), q : »¬¼ÀÀ» ÇØÁÙ Á¡µéÀÇ °¹¼ö 
{
	if (R == 0)
	{
		int sum_x_temp = sum_x; 
		int sum_y_temp = sum_y; 
		for (int i = 0; i < q; i++)
		{
			sum_x_temp -= 2 * x[a[i]];
			sum_y_temp -= 2 * y[a[i]];
		}

		temp = sqrt(pow(sum_x_temp, 2) + pow(sum_y_temp, 2)); 

		if (temp < ans) ans = temp; 

	}
	else if (N < R) return; 

	else
	{
		a[R - 1] = N - 1;
		combination(N - 1, R - 1, q); 
		combination(N - 1, R, q);
	}
}

int main(void)
{

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		sum_x = 0;
		sum_y = 0;
		ans = MAX; 
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			scanf("%d %d", &x[j], &y[j]);
			sum_x += x[j]; 
			sum_y += y[j]; 
		}

		combination(N, N / 2, N / 2); 
		printf("%.12f\n", ans); 
	}

}