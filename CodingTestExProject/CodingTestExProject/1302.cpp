/*
1302 ����Ʈ ����

�������� ž������ �����̴�. �������� ���뿡�� ����� �ϴ� �����̴�. �������� �׳� �ٹ��� ���� �Ŀ�, ���� �Ǹ��� å�� ������ ���鼭 ���� ���� �ȸ� å�� ������ ĥ�ǿ� ����� �ϵ� ���� �ϰ� �ִ�.

���� �Ϸ� ���� �ȸ� å�� ������ �Է����� ������ ��, ���� ���� �ȸ� å�� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
https://www.acmicpc.net/problem/1302

�� Ȱ�� ����

�� �ẻ���� ���� ������ �̿� ���� ���������� �����ϰ� �� �� �ִ�.
(���ڿ� ���� �������� �� ������ ���)
���� key���� ������������ ���ĵǸ� value�� �����ϱ� ���ؼ� sort�Լ��� ����° ���ڰ��� Ȱ���ϸ� �ȴ�.
https://0xd00d00.github.io/2021/08/22/map_value_reverse.html

map �̿��
https://kimcoder.tistory.com/122
*/
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int N;
	cin >> N;
	map<string, int> m;
	int arr[1001] = { 0, };
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (m.find(s) == m.end())
			m.insert({ s,1 });
		else
			m[s]++;
	}
	int max = 0;
	string ans = "";
	for (auto i : m)
	{
		if (max < i.second)
		{
			max = i.second;
			ans = i.first;
		}
	}
	cout << ans;
	return 0;
}