
/*
4179 - 불!
https://www.acmicpc.net/problem/4179

문제에서 불이 발생할 수 있는 개수는 1개가 아니라서 불에 대해 따로 처리가 필요하다.
불의 이동 게산 -> 지훈이의 이동 가능 판별 ->  답

2차원 배열 초기화 잘못하고 있어서 30분 정도 버린듯
memset 사용하지말고 algorithm 에 있는 fill 사용하자
fill(시작 주소,끝 주소,값); 으로 사용하면 된다.

*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1e9

int R,C;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

char map[1001][1001] = {0,};
int visited[1001][1001] = {0,};
int fireVisited[1001][1001] = {0,};
queue<pair<int,int>> q;

void FIRE_BFS()
{
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		for(int i = 0;i<4;i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
		
			
			if(nx<0||ny<0||nx>=R||ny>=C)
				continue;
			
			if(map[nx][ny]=='#')
				continue;
				
			if(map[nx][ny]=='F')
				continue;	
				
			if(fireVisited[nx][ny] != INF)
				continue;
		
			fireVisited[nx][ny] = fireVisited[cx][cy] + 1;
			q.push({nx,ny});
		}
	}
}

void BFS()
{
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		for(int i = 0;i<4;i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx<0||ny<0||nx>=R||ny>=C)
			{
				cout<<visited[cx][cy]+1<<endl;
				return;
			}
			
			if(fireVisited[nx][ny]<=visited[cx][cy]+1)
				continue;
			
			if(map[nx][ny]=='#')
				continue;
				
			if(map[nx][ny]=='F')
				continue;	
				
			if(visited[nx][ny])
				continue;
			
			visited[nx][ny] = visited[cx][cy] + 1;
			q.push({nx,ny});
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}

void print()
{
	for(int i = 0 ;i<C; i++)
	{
		for(int j = 0; j<R; j++)
		{
			if(fireVisited[j][i]==INF)
				cout<<"X"<<" ";
			else
				cout<<fireVisited[j][i]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;
	
	for(int i = 0 ;i<C; i++)
	{
		for(int j = 0; j<R; j++)
		{
			cout<<visited[j][i];
		}
		cout<<endl;
	}
}

int main() {
	
	cin>>C>>R;
	pair<int,int> jihoon;
	
	fill(&fireVisited[0][0], &fireVisited[R][C], INF);
	
	for(int y = 0;y<C;y++)
	{
		for(int x = 0;x<R;x++)
		{
			cin>>map[x][y];
			
			if(map[x][y]=='F')
			{
				q.push({x,y});
				fireVisited[x][y] = 0;
			}
			
			if(map[x][y]=='J')
			{
				jihoon = {x,y};
			}
		}
	}

	FIRE_BFS();
	
	q.push(jihoon);
	
	BFS();


	return 0;
}