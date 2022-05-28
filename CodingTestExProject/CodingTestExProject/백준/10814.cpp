/*
10814

stable_sort() �˱⸸ �ϸ� �Ǵ� ����
�ش� �Լ��� ���� ���� �ϴ� ���� ���� ����� �����ߴ� ����
stable_sort ����° ���ڷ� �� ���Ҹ� ���� �Լ��� �־������Ѵ�.

N �� �����ϴ� ������ ���� (N = std::distance(first, last)) ��� �� ��, O(N(logN)2)�̴�. ���� �߰����� �޸𸮸� ����� �� �ִٸ� ���⵵�� O(N\log N)O(NlogN) ���� �پ���.

���繮��
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