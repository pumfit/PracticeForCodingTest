/*
2042 구간 합 구하기

어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다. 만약에 1,2,3,4,5 라는 수가 있고, 3번째 수를 6으로 바꾸고 2번째부터 5번째까지 합을 구하라고 한다면 17을 출력하면 되는 것이다. 그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 3번째부터 5번째까지 합을 구하라고 한다면 12가 될 것이다.

https://www.acmicpc.net/problem/2042

세그먼트 트리
https://www.acmicpc.net/blog/view/9

*/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class SegmentTree {
private:
    vector<ll> tree;
    int n;
ß
    ll Init(vector<ll>& arr, int node, int start, int end) {
        // 리프 노드 가장 마지막 노드 값들이 배열의 그 수 자체 값을 가진다.
        if (start == end) {
            return tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            // 부모 노드는 왼쪽 자식과 오른쪽 자식의 합을 저장하여 구간 합을 저장한다.
            return tree[node] = Init(arr, node * 2, start, mid) + Init(arr, node * 2 + 1, mid + 1, end);
        }
    }

    ll sum(int node, int start, int end, int left, int right) {

        if (left > end || right < start) 
            return 0; // 구간이 겹치지 않음
        
        if (left <= start && end <= right) 
            return tree[node]; // 구간이 완전히 포함됨

        int mid = (start + end) / 2;

        return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
    }

    // 업데이트 연산
    // diff 값은 index번째 수를 val로 변경한다면, 그 수의 변화 값
    void Update(int node, int start, int end, int index, ll diff) {

        if (index < start || index > end) // 범위 밖의 인덱스
            return; 
        
        tree[node] += diff; // 합을 변화량 만큼 변경시킴
        
        if (start != end) {
            int mid = (start + end) / 2;
            Update(node * 2, start, mid, index, diff);
            Update(node * 2 + 1, mid + 1, end, index, diff);
        }
    }

public:
    SegmentTree(vector<ll>& arr) {
        n = arr.size();
        tree.resize(n * 4);
        Init(arr, 1, 0, n - 1);
    }

    ll Sum(int left, int right) {
        return sum(1, 0, n - 1, left, right);
    }

    void Update(int index, ll new_value, vector<ll>& arr) {
        ll diff = new_value - arr[index];
        arr[index] = new_value;
        Update(1, 0, n - 1, index, diff);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<ll> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    SegmentTree segmentTree(arr);

    for (int i = 0; i < M + K; i++) {

        int a, b;
        ll c;

        cin >> a >> b >> c;

        if (a == 1) {
            segmentTree.Update(b - 1, c, arr);
        } else if (a == 2) {
            cout << segmentTree.Sum(b - 1, c - 1) << '\n';
        }
    }

    return 0;
}
