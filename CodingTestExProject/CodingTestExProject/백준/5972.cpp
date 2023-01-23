/*
5972 택배 배송
https://www.acmicpc.net/problem/5972

다익스트라 복습하기
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 1e9

vector<pair<int,int>> m[50001];
int N, M;
int visited[50001] = {0,};

void Dijkstra()
{
	priority_queue<pair<int,int>> pq;
	pq.push({0,1});
	visited[1] = 0;
	
	while(!pq.empty())
	{
		int dist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		
		if(visited[cur]<dist)
			continue;
			
		for(int i = 0;i<m[cur].size();i++)
		{
			int cost = dist + m[cur][i].second;
			
			if(cost <visited[m[cur][i].first])
			{
				visited[m[cur][i].first]=cost;
                pq.push(make_pair(-cost,m[cur][i].first));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>M;
	int a,b,c;
	for(int i = 0;i<M;i++)
	{
		//two way
		cin>>a>>b>>c;
		m[a].push_back({b,c});
		m[b].push_back({a,c});
	}
	fill(visited, visited + 50001, INF);
	Dijkstra();
	cout<<visited[N];
	return 0;
}