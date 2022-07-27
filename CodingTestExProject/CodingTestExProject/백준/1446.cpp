/*
1446 지름길

다익스트라 연습문제로 고른문제지만 읽어보면 DP느낌이 난다.
이후에 DP로 풀어볼 것

우선순위 큐에 cost를 저장할때 음수로 만들어서 저장하는데
이는 우선순위큐에서 거리가 짧은 경우가 먼저 오게 하기 위함이다.
(-10 <- -20 <- -30) (30 <- 20 <- 10)

다익스트라로 풀면서 구간내 값이 없는 경우에는 어떻게 풀지 감이 오지 않았는데
큐에 들어가는 경우 계속 판단을 하므로 for문으로 현재 지점에서의 노드 탐색을 끝낸 후
1보다 큰 노드에서 최소값이 현재 노드의 비용 + 1 보다 큰지 판단한 후 비용을 갱신하고 해당되는 값을 큐에 추가해주면 된다.

DP도 top down 방식으로 반대로 현재 인덱스의 -1 의 비용에 대해 판단하면서 진행하면 될 것 같다.
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
	pq.push({ 0,n });//비용과 인덱스
	minCost[n] = 0;//출발지 최소비용 0

	while (!pq.empty())
	{
		int curCost = -pq.top().first;//비용
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