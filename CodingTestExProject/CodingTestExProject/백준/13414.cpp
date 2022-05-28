/*
13414 ������û

https://www.acmicpc.net/problem/13414

���δ��б������� �� �б� ���� �� ���������ý��ۿ��� ������û�� �Ѵ�. �� ������û���� ���� ���� �л����� ���� ������ ���� ���ϰ� ���� ������, ���δ��б������� ������û ���� ���� �ý����� �����ϱ�� �����Ͽ���. ���ο� ���� �ý����� ������ ���� ������� �����Ѵ�.

������û ��ư�� Ȱ��ȭ �� ��, ������û ��ư�� �����̶� ���� ���� �л��� ����Ͽ� ���� ����.
�̹� ��⿭�� �� �ִ� ���¿��� �ٽ� ������û ��ư�� ���� ��� ������� �� �ڷ� �з�����.
��� �� ������û ��ư�� ��Ȱ��ȭ �Ǹ�, ����Ͽ��� ���� �տ� �ִ� �л����� �ڵ����� ������û�� �Ϸ�Ǹ�, ���� ���� �ο��� �� �� ��� ������ ������� �����ϰ� ������û�� �����Ѵ�.

������ ������ ������ ���� ��� ������Ʈ �ϴ� ������� Ǯ����.
�ٸ� ��� ���̽��� �־ Ʋ�Ⱦ��µ� 
��¿� �־� v�� ũ�⺸�� ū ���� ��µǴ� ��쿡 ���� ���� ó���� ������ �ʾƼ�����.
�������� map�� value�� �����ϴ� ����� ����ؼ� compare�Լ� ����� ������ �����ߴ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b)
{
	return a.second >= b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	unordered_map<string, int> m;
	int N, T;
	cin >> N >> T;
	while (T--)
	{
		string num;
		cin >> num;
		m[num] = T;
	}
	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < N; i++)
	{
		if (i > v.size() - 1)
			break;
		cout << v[i].first << '\n';
	}
	return 0;
}