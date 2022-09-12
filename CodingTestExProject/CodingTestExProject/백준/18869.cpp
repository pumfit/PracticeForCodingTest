/*
18869 ��Ƽ ����2
https://www.acmicpc.net/problem/18869

��ǥ ���� Ǯ�̸� �˰� �־�� ���� Ǯ�� ����� ���̴� ����
�� �༺ ũ�⸦ ������ �� ������ Ȯ���غ��� �ȴ�.

- ��ǥ ���Ҷ� ����ũ ����ؼ� �ߺ� �� ���ֱ�
- ���� ���� �� ã�� ����

 ó���� �� ����ؼ� ���� 2�̻��̸� ������ 1 �������״µ� �ش� ������δ� ��� Ʋ�Ȱ�
 ���� for������ ���� �ٿ����鼭 �ϸ� �������� ó���Ǿ���.

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N, M, n;

bool compare(string a, string b) {
	for (int k = 0; k < M; k++)
	{
		if (a[k] != b[k])
			return false;
	}
	return true;
}

int main() {
	int answer = 0;
	vector<int> v[101];
	map<string, int> m;
	vector<string> str;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> n;
			v[i].push_back(n);
		}
		vector<int> sort_v(v[i].begin(), v[i].end());
		sort(sort_v.begin(), sort_v.end());
		sort_v.erase(unique(sort_v.begin(), sort_v.end()), sort_v.end());
		string s = "";
		for (int j = 0; j < M; j++)
		{
			s += (lower_bound(sort_v.begin(), sort_v.end(), v[i][j]) - sort_v.begin()) + '0';
		}
		str.push_back(s);
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			answer += compare(str[i], str[j]);
		}
	}
	cout << answer;
	return 0;
}