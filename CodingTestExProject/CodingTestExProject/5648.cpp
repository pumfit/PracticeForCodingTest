/*
5648 역원소 정렬

모든 원소가 양의 정수인 집합이 있을 때, 원소를 거꾸로 뒤집고 그 원소를 오름차순으로 정렬하는 프로그램을 작성하세요.

단, 원소를 뒤집었을 때 0이 앞에 선행되는 경우는 0을 생략해야합니다.

첫 번째로 입력되는 건 n (1 ≤ n ≤ 10^6)으로 사용자가 뒤이어 입력할 원소값을 결정합니다. 입력하는 줄에는 하나의 원소값 뿐만 아니라 여러 원소값도 들어갈 수 있습니다.

단, 입력하는 정수는 10^12을 넘어선 안 됩니다.

되게 쉽게 생각했다가 런타임 에러뜬 문제
입력 범위가 10^6이고 들어오는 정수값은 10^12이라  int내에서 처리가 불가능해 long long으로 변환해야한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long> v;
	while (N--)
	{
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		v.push_back(stoll(s));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
	return 0;
}