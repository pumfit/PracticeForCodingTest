/*
* 1967 Ʈ���� ���� 

OOB ������ ���Ĺ����� �� �˾Ҵ� ����

ó���� ���� �����ϰ� ��ü��忡�� ����ġ �ִ� �յ��� ã�� �ִ밪�� ����ߴ�.
�ش� Ǯ�̵� ü������� 100���� ���� �� ��Ÿ�ӿ�����  OutOfBounds�� ���԰�

���� ����� �ٸ� Ǯ�̵� ���ϱ� ������ ��忡�� ���� �� ��带 ã�� �ش� ��忡�� ���� �� �������� �Ÿ��� �������� �˰ԵǾ���.

���ɳ� �ٸ� Ǯ��, ������ ���� �𸣴ٰ� �Է� ���̽��� ���� �ٽ� �ôµ�
12�� ������ n-1���� �����µ� ������ 0 ���� N���� �����صΰ� �־���...�̺κ� �������ִϱ� ����ߴ�
��Ÿ�ӿ����� 4�� ������ ����

Ʈ���� Ư¡ + DFS �����ؼ� �� �� ����Ǯ��� �� ������ ���� �� ����
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N = 0;
int answer = 0;
int maxNode = 0;
int maxCost = 0;

vector<pair<int, int>> tree[10005];
int visited[10005] = { 0, };

void DFS(int n, int sum)
{
	if (visited[n])
		return;
	if (sum > maxCost)
	{
		maxCost = sum;
		maxNode = n;
	}
	visited[n] = 1;
	for (int i = 0; i < tree[n].size(); i++)
	{
		int next = tree[n][i].first;
		int cost = tree[n][i].second;
		DFS(next, sum + cost);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int S, E, C;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> S >> E >> C;
		tree[S].push_back({ E,C });
		tree[E].push_back({ S,C });
	}

	DFS(1, 0);

	maxCost = 0;
	memset(visited, 0, sizeof(visited));

	DFS(maxNode, 0);

	cout << maxCost;
	return 0;
}