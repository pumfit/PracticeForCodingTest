/*
2146 다리 만들기
https://www.acmicpc.net/problem/2146

BFS
1. 각 섬마다 넘버링 진행하기
    이때, 이후 거리를 계산할때 양수를 사용하므로 구분을 음수로 진행함

2. 섬인 경우 BFS 진행
    다른 섬에 도착한 경우, 최소값인지 확인하고 종료
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int map[101][101] = {0,};

int N;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int visited[101][101] = {0,};
int land = -1;

int minLength = 2e9;

void FindMinLength(int x,int y,int type)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	visited[x][y] = 1;
	
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		for(int i = 0;i<4;i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(map[nx][ny]<0&&map[nx][ny]!=type)
			{
				// reach difference map
				minLength = min(minLength,visited[cx][cy]-1);
				return;
			}
			
			if(nx<0||ny<0||nx>=N||ny>=N)
				continue;
				
			if(map[nx][ny]==type) // 같은 섬 내의 진행인 경우 
				continue;
				
			if(visited[nx][ny]) // 이미 방문한 경우
				continue;
				
			visited[nx][ny] = visited[cx][cy] +1;
			q.push({nx,ny});
				
		}
	}
}

void BFS(int x,int y)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	map[x][y] = land;
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		for(int i = 0;i<4;i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx<0||ny<0||nx>=N||ny>=N)
				continue;
				
			if(map[nx][ny]==land||map[nx][ny]==0)
				continue;
				
			map[nx][ny] = land;
			q.push({nx,ny});
				
		}
	}
}

int main() {

	cin>>N;
	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<N;j++)
		{
			cin>>map[i][j];
		}
	}

	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<N;j++)
		{
			if(map[i][j]==1)
			{
				BFS(i,j);
				land--;
			}
		}
	}

	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<N;j++)
		{
			if(map[i][j]<0)
			{
				FindMinLength(i,j,map[i][j]);
				memset(visited,0,sizeof(visited));
			}
		}
	}

	cout<<minLength;
	return 0;
}