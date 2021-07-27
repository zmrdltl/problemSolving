//segment tree, 세그먼트 트리, 세그트리
#include <bits/stdc++.h>
#define SIZE 12
using namespace std;
//구간을 반으로 나누어 그 절반의 전체 합이 부모노드가 됨
//tree크기 : n개 data에 대해 n보다 큰고 가까운 제곱수x2만큼
//따라서 가까운제곱수 * 2 < n*4이므로 n*4만큼 할당함
int a[] = {1,9,3,8,4,5,5,9,10,3,4,5};
int tree[SIZE * 4];

//구간합 만들기
int init(int start, int end, int node){
    if(start == end) return tree[node] = a[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}


//해당 범위에 속한 구간들을 모두 더하기
int sum(int start, int end, int node, int left, int right){
    //범위 밖이라면
    if(left > end || right < start) return 0;
    //범위 안에 있으면 return
    if(left <= start && end <= right) return tree[node];
    //범위 밖이지만 유효한 범위일 때
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

//index:수정하고자 하는 노드번호
//diff : 수정해야하는 값
void update(int start, int end, int node, int index, int diff){
    if(index < start || index > end) return;
    //범위 안이라면 내려가며 다 갱신
    tree[node] += diff;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, diff);
    update(mid + 1, end, node * 2 + 1, index, diff);
}

int main(){
    init(0, SIZE-1, 1);
    cout << "0 ~ 12구간 합 : " << sum(0, SIZE - 1, 1, 0, 12) << '\n';
    cout << "3 ~ 8구간 합 : " << sum(0, SIZE - 1, 1, 3, 8) << '\n';

    cout << "인덱스 5의 원소를 -5로 수정 \n";
    update(0, SIZE - 1, 1, 5, -5);
    cout << "3부터 8까지의 구간 합: " << sum(0, SIZE - 1, 1, 3, 8) << '\n';
}
