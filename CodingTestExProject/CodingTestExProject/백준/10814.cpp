/*
10814

stable_sort() 알기만 하면 되는 문제
해당 함수에 대해 몰라서 일단 벡터 페어로 만들고 생각했던 문제
stable_sort 세번째 인자로 두 원소를 비교할 함수가 주어져야한다.

N 을 전달하는 원소의 개수 (N = std::distance(first, last)) 라고 할 때, O(N(logN)2)이다. 만일 추가적인 메모리를 사용할 수 있다면 복잡도는 O(N\log N)O(NlogN) 으로 줄어든다.

유사문제
https://programmers.co.kr/learn/courses/30/lessons/17686?language=cpp

https://modoocode.com/323
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool compare(pair<int, string> a, pair<int, string>b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	vector<pair<int, string>> v;
	for (int i = 0; i < N; i++)
	{
		int A; string B;
		cin >> A >> B;
		v.push_back(make_pair(A, B));
	}
	stable_sort(v.begin(), v.end(), compare);
	for (int i = 0; i < N; i++)
	{
		cout << v[i].first << " " << v[i].second << '\n';
	}
	return 0;
}