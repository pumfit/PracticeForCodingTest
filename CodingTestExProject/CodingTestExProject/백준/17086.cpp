/*
https://www.acmicpc.net/problem/17086

방문 시  값 갱신하는 방식으로 풀었는데 각 시작점에 대해 한번씩 실행하는게 아니라 시작점을 모두 넣고 한번만 넣어주면 빠르게 풀이가 가능하다는 걸
이후 다른 풀이를 보고 알게 되었다.

Point.
동일한 시점에 시작하는 경우 Queue에서 시작점을 초기화하고 구현하면 된다.

다시풀기

*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

bool visited[52][52] = {0,};
int safeDistance[52][52] = {0,};
int map[51][51] = {0,};
int dx[8] = {0,0,1,-1,1,-1,-1,1};
int dy[8] = {-1,1,0,0,1,-1,1,-1};
int maxDistance = 0;
int N,M;

void bfs(int x,int y)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	safeDistance[x][y] = 1;
	visited[x][y] = 1;
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(int i = 0;i<8;i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(visited[nx][ny])
				continue;
			if(map[nx][ny]==1)
				continue;
			if(nx<0||ny<0||N<=ny||M<=nx)
				continue;
			visited[nx][ny] = 1;
			if(safeDistance[nx][ny]==0||(safeDistance[nx][ny]!=0&&safeDistance[cx][cy] + 1 < safeDistance[nx][ny]))
				safeDistance[nx][ny] = safeDistance[cx][cy] + 1;
			q.push({nx,ny});
		}
	}
}
int main() {
	cin>>N>>M;
	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<M;j++)
		{
			cin>>map[j][i];
		}
	}
	
	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<M;j++)
		{
			if(map[j][i]==1)
			{
				bfs(j,i);
				memset(visited,0,sizeof(visited));
			}
		}
	}
	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<M;j++)
		{
			maxDistance = max(maxDistance,safeDistance[j][i]);
		}
	}
	cout<<maxDistance-1;
	return 0;
}