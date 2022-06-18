/*
1916 �ּҺ�� ���ϱ�

https://www.acmicpc.net/problem/1916

N���� ���ð� �ִ�. �׸��� �� ���ÿ��� ����Ͽ� �ٸ� ���ÿ� �����ϴ� M���� ������ �ִ�. �츮�� A��° ���ÿ��� B��° ���ñ��� ���µ� ��� ���� ����� �ּ�ȭ ��Ű���� �Ѵ�. 
A��° ���ÿ��� B��° ���ñ��� ���µ� ��� �ּҺ���� ����Ͽ���. ������ ��ȣ�� 1���� N�����̴�.


�ּ� ����� ���ϴ� ���� �Ÿ� ���� ���� ���ͽ�Ʈ�� �˰��� ����

1���� �����̴� ���� �ʱ�ȭ�� �迭+N�� ������ ��� ���� ������ �ʾҴ�.
�̺κ��� �����ϰ� Ǯ�����

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9

vector<pair<int, int>> city[1001];// �׷���
int d[1001];
int N, M;//���� ���� ���� ���� 
int start, target;

void dij(int s)
{
	//STEP 4 . �켱���� ť�� ����� ���� �ֱ� 
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s }); // ��������� ���, ���� ��ġ
	d[s] = 0;//������� �ּ� ��� 0

	while (!pq.empty())
	{
		//STEP 4 . ť���� ���� �ϳ� ������ 
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		//STEP 5 . �̹� �ּҰŸ��� ã�� ��쿡�� pass
		if (d[now] < dist)
			continue;
		for (int i = 0; i < city[now].size(); i++)//STEP 4 . ��忡 ����� ������ŭ ��� ��
		{
			int cost = dist + city[now][i].second;
			if (cost < d[city[now][i].first])
			{
				d[city[now][i].first] = cost;
				pq.push({ -cost,city[now][i].first });

			}
		}
	}
}

int main() {
	cin >> N >> M;
	//STEP 1 . �׷��� ä��� (�ܹ���)
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		city[a].push_back({ b,c });
	}
	cin >> start >> target;
	//STEP 2 . �ּ� ��� ���� �迭 �ʱ�ȭ 
	fill(d, d + N + 1, INF);
	//STEP 3 . ���ͽ�Ʈ�� �˰���
	dij(start);
	cout << d[target];
	return 0;
}