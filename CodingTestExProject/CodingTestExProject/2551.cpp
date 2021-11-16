/*
2551 ����

���������� �ʹ� ������� ���� DP�ΰ� �� �������ٰ� Ư���� ������ ����
���� ��찡 �����ؼ� dfs,bfs�� Ǯ��� �ڴ� �����ϰ� ����� �б����� ����
bfs�� ��ü Ž���ϴ� ����� ����� �Ѵٴ� ���� �˰� �Ǿ���. �ٸ�
��� ���� �ű� �������� ���� ������ �������.

���� �ڵ�
https://rebas.kr/769
���� ������
https://maybemine.tistory.com/entry/BOJ2251-%EB%AC%BC%ED%86%B5-BFS PW:1116

*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int A, B, C;
int visited[201][201] = {0,};
queue<pair<int, int>> q;
vector<int> v;

void pour(int a, int b)
{
	if (!visited[a][b])
	{
		visited[a][b] = 1;
		q.push(make_pair(a, b));
	}
}

void bfs()
{
	q.push(make_pair(0, 0));
	visited[0][0] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int z = C - x - y;
		q.pop();
		if (x == 0)
			v.push_back(z);
		// A->B �� �ű�� ���
		int water = min(x, B - y);//�ѱ� ���� �� a�� b�� ���ؼ� ��ġ�� �ʴ� ���, ��ġ�� ���
		pour(x - water, y + water);
		// A->C
		water = min(x, C - z);
		pour(x - water, y);
		// B->A
		water = min(y, A - x);
		pour(x + water, y - water);
		// B->C
		water = min(y, C - z);
		pour(x, y - water);
		// C->A
		water = min(z, A - x);
		pour(x + water, y);
		// C->B
		water = min(z, B - y);
		pour(x, y + water);
	}
}

int main()
{
	cin >> A >> B >> C;
	bfs();
	sort(v.begin(), v.end());
	for (int i=0;i<v.size();i++)
		cout << v[i] << " ";
}