/*
1916 최소비용 구하기

https://www.acmicpc.net/problem/1916

N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 M개의 버스가 있다. 우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. 
A번째 도시에서 B번째 도시까지 가는데 드는 최소비용을 출력하여라. 도시의 번호는 1부터 N까지이다.


최소 비용을 구하는 음의 거리 없는 완전 다익스트라 알고리즘 문제

1부터 시작이다 보니 초기화를 배열+N로 진행한 경우 답이 나오질 않았다.
이부분을 유의하고 풀어야함

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9

vector<pair<int, int>> city[1001];// 그래프
int d[1001];
int N, M;//도시 개수 버스 개수 
int start, target;

void dij(int s)
{
	//STEP 4 . 우선순위 큐에 출발점 부터 넣기 
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s }); // 현재까지의 비용, 현재 위치
	d[s] = 0;//출발점의 최소 비용 0

	while (!pq.empty())
	{
		//STEP 4 . 큐에서 정점 하나 꺼내기 
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		//STEP 5 . 이미 최소거리를 찾은 경우에는 pass
		if (d[now] < dist)
			continue;
		for (int i = 0; i < city[now].size(); i++)//STEP 4 . 노드에 연결된 엣지만큼 비용 비교
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
	//STEP 1 . 그래프 채우기 (단방향)
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		city[a].push_back({ b,c });
	}
	cin >> start >> target;
	//STEP 2 . 최소 비용 담을 배열 초기화 
	fill(d, d + N + 1, INF);
	//STEP 3 . 다익스트라 알고리즘
	dij(start);
	cout << d[target];
	return 0;
}