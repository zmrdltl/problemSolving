#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, a, b;
int p[100001];

struct Tree {
	vector<int> rangeMin;
	vector<int> rangeMax;
	Tree() {
		rangeMin.resize(N * 4);
		rangeMax.resize(N * 4);
		initMin(0, N - 1, 1);
		initMax(0, N - 1, 1);
	}
	int initMin(int left, int right, int node) {
		if (left == right)
			return rangeMin[node] = p[left];
		int mid = (left + right) / 2;
		rangeMin[node] = min(initMin(left, mid, node * 2), initMin(mid + 1, right, node * 2 + 1));
		return rangeMin[node];
	}
	int initMax(int left, int right, int node) {
		if (left == right)
			return 	rangeMax[node] = p[left];
		int mid = (left + right) / 2;
		rangeMax[node] = max(initMax(left, mid, node * 2), initMax(mid + 1, right, node * 2 + 1));
		return rangeMax[node];
	}
	int queryMin(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (nodeRight < left || right < nodeLeft) return 1000000000;
		if (left <= nodeLeft && nodeRight <= right) return rangeMin[node];
		int mid = (nodeLeft + nodeRight) / 2;
		int tmp_min = min(queryMin(left, right, node * 2, nodeLeft, mid), queryMin(left, right, node * 2 + 1, mid + 1, nodeRight));
		return tmp_min;
	}
	int queryMax(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (nodeRight < left || right < nodeLeft) return 1;
		if (left <= nodeLeft && nodeRight <= right) return rangeMax[node];
		int mid = (nodeLeft + nodeRight) / 2;
		int tmp_max = max(queryMax(left, right, node * 2, nodeLeft, mid), queryMax(left, right, node * 2 + 1, mid + 1, nodeRight));
		return tmp_max;
	}
	void query(int left, int right) {
		int resMin = queryMin(left, right, 1, 0, N - 1);
		int resMax = queryMax(left, right, 1, 0, N - 1);
		printf("%d %d\n", resMin, resMax);
	}
};

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &p[i]);
	Tree t;
	while (M--) {
		scanf("%d %d", &a, &b);
		t.query(a-1, b-1);
	}
}