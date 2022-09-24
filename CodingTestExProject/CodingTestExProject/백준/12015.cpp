/*
12015 ���� �� �����ϴ� �κ� ����2

https://www.acmicpc.net/problem/12015
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, n;
	cin >> N;
	vector<int> v;
	cin >> n;
	v.push_back(n);
	for (int i = 1; i < N; i++)
	{
		cin >> n;
		if (v[v.size() - 1] < n) //step1. �Է°��� �迭�� ������������ ū ��쿡�� �迭�� �߰��Ѵ�.
			v.push_back(n);
		else //step2. �Է°��� �迭�� ������������ ���� ���� �迭���� ���ų� ū ���� �Է°����� �ٲ۴�.
		{
			v[lower_bound(v.begin(), v.end(), n) - v.begin()] = n;
		}
	}
	cout << v.size();
	return 0;
}