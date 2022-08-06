/*
1238 파티

왕복 최단 거리를 구하고 그중 최대를 찾는 문제여서 전체 학생 배열 돌면서 최단거리 구하고 
단방향이고 왕복이 달라질 수 있어서 다익스트라로 경로 찾는 걸 두번 진행하면 된다.

그런데 한번 시간초과로 틀려서 다른 알고리즘이 있나 싶어 찾아봤는데 입출력 속도 때문이었다.
ios::sync_with_stdio(false); 쓰고 cin,cout 쓰도록 습관 꼭 들이자

+)
목표가 자기마을인 경우는 계산하지 않으면 더 빠를 것 같아서 if(i+1==X) continue; 추가해서 제출했는데
시간상으론 조건문 넣은 게 더 시간이 오래걸렸다. 1개 건너뛰는 거라 크게 차이가 없었는 것 같다
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9

int N, M, X;//학생 단방향도로 마을
vector<pair<int, int>> v[1001];
int d[1001];
int maxDist = 0;

void BFS(int s)
{
	priority_queue<pair<int, int>> q;
	q.push({ s,0 });
	d[s] = 0;
	while (!q.empty())
	{
		int now = q.top().first;
		int dist = -q.top().second;
		q.pop();

		if (d[now] < dist)
			continue;

		for (int i = 0; i < v[now].size(); i++)
		{
			int cost = dist + v[now][i].second;
			if (cost < d[v[now][i].first])
			{
				d[v[now][i].first] = cost;
				q.push({ v[now][i].first,-cost });
			}
		}
	}

}

int FindMinPath(int start, int end)
{
	fill(d, d + 1001, INF);
	BFS(start);
	return d[end];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X;
	int A, B, C;
	while (M--)
	{
		cin >> A >> B >> C;
		v[A].push_back({ B,C });
	}
	for (int i = 0; i < N; i++)
	{
		if (i + 1 == X)
			continue;
		int dist = 0;
		dist += FindMinPath(i + 1, X);
		dist += FindMinPath(X, i + 1);
		maxDist = max(maxDist, dist);
	}
	cout << maxDist;
	return 0;
}