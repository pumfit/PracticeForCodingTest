/*
11650 ��ǥ �����ϱ�

�ð��ʰ����� ��Ȳ������
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); �߰��ϰ� endl ���� '\n'���� ������ 48ms�� ����ߴ�.
������ �̴� pair�� Ȱ���� Ǯ�̶� �ش� Ǯ�̿� �ٸ� Ǯ�̰� ���� ���캸�Ҵ�.
��κ�  pair�� Ȱ���� ����Ǯ�� ����̾��� sort�� ����� �����Լ��� ����ϴ� ����� �־���.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int T;
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << "\n";
	return 0;
}