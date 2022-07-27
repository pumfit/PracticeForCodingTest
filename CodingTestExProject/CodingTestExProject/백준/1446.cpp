/*
1446 ������

���ͽ�Ʈ�� ���������� ���������� �о�� DP������ ����.
���Ŀ� DP�� Ǯ� ��

�켱���� ť�� cost�� �����Ҷ� ������ ���� �����ϴµ�
�̴� �켱����ť���� �Ÿ��� ª�� ��찡 ���� ���� �ϱ� �����̴�.
(-10 <- -20 <- -30) (30 <- 20 <- 10)

���ͽ�Ʈ��� Ǯ�鼭 ������ ���� ���� ��쿡�� ��� Ǯ�� ���� ���� �ʾҴµ�
ť�� ���� ��� ��� �Ǵ��� �ϹǷ� for������ ���� ���������� ��� Ž���� ���� ��
1���� ū ��忡�� �ּҰ��� ���� ����� ��� + 1 ���� ū�� �Ǵ��� �� ����� �����ϰ� �ش�Ǵ� ���� ť�� �߰����ָ� �ȴ�.

DP�� top down ������� �ݴ�� ���� �ε����� -1 �� ��뿡 ���� �Ǵ��ϸ鼭 �����ϸ� �� �� ����.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9+7

vector<pair<int, int>> graph[10001];
int minCost[10001];
int N, M;

void findPath(int n)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,n });//���� �ε���
	minCost[n] = 0;//����� �ּҺ�� 0

	while (!pq.empty())
	{
		int curCost = -pq.top().first;//���
		int now = pq.top().second;
		pq.pop();

		if (minCost[now] < curCost)
			continue;

		for (int i = 0; i < graph[now].size(); i++)
		{
			int cost = curCost + graph[now][i].second;
			if (cost < minCost[graph[now][i].first])
			{
				minCost[graph[now][i].first] = cost;
				pq.push({ -cost,graph[now][i].first });
			}
		}
		if (now + 1 <= M && minCost[now + 1] > curCost + 1) {
			minCost[now + 1] = curCost + 1;
			pq.push({ -(curCost + 1),now + 1 });
		}
	}

	return;
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		graph[A].push_back({ B,C });
	}

	fill(minCost, minCost + 10001, INF);

	findPath(0);

	cout << minCost[M];
	return 0;
}