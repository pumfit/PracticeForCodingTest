/*
2668 ���ڰ���
https://www.acmicpc.net/problem/2668

���� �� ��, ���η� N���� ĭ���� �̷���� ǥ�� �ִ�. ù° ���� �� ĭ���� ���� 1, 2, ��, N�� ���ʴ�� ��� �ְ� ��° ���� �� ĭ���� 1�̻� N������ ������ ��� �ִ�. ù° �ٿ��� ���ڸ� ������ ������, �� ���� �������� �̷�� ���հ�, ���� �������� �ٷ� ���� ��° �ٿ� ����ִ� �������� �̷�� ������ ��ġ�Ѵ�. 
�̷��� ������ ������Ű���� �������� �̵�, �ִ�� ���� �̴� ����� ã�� ���α׷��� �ۼ��Ͻÿ�.

1~ N���� ����Ŭ ������ �� �Ǵ��ϴ� ���� ����Ŭ�� �����ٸ� ������ �����ϸ� �ȴ�.

*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int cnt = 0;
int arr[101] = { 0, };
int visited[101] = { 0, };
vector<int> v;

bool DFS(int s, int i)
{
	if (visited[i])
	{
		if (s == i)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		visited[i] = 1;
		return DFS(s, arr[i]);
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		if (DFS(i, i))
		{
			v.push_back(i);
			cnt++;
		}
		memset(visited, 0, sizeof(visited));
	}
	cout << cnt << '\n';
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
	return 0;
}