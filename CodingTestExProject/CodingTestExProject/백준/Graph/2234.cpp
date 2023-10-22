/*
2234 성곽

https://www.acmicpc.net/problem/2234

bfs 후 각 영역에 대해 다시 bfs를 돌면서 벽을 허물고 허문 벽이 다른 방이라면 그 방의 크기 값을 더해 방의 크기를 계산했다.

+ 방 사이즈 잘못 잡고 방의 크기를 구하는 문제인데 처음에 visited로 거리계산하려 그래서 시간 많이 빼먹었던 문제 bfs 관련 복습 및 비트마스크 응용이라 좋은 예제인 것 같다.
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int map[51][51] = {0,};
int room[51][51] = {0,};
int visited[51][51] = {0,};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int roomCnt = 0;
int maxRoomSize = 0;
int maxMergeRoomSize = 0;
int N,M;
int roomSizes[2501] = {0,};

void findMaxMergeRoomSize(int x,int y,int curType)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	visited[x][y] = 1;
	
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		for(int i = 0; i<4;i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx<0||ny<0||nx>=N||ny>=M)
				continue;
			
			if(map[cx][cy]&(1<<i))
			{
				if(room[nx][ny]!=curType)
				{
					maxMergeRoomSize = max(roomSizes[curType]+roomSizes[room[nx][ny]],maxMergeRoomSize);
				}
			}else{
                if(visited[nx][ny])
					continue;
				if(room[nx][ny]!=curType)
					continue;
				visited[nx][ny] = visited[cx][cy]+1;
				q.push({nx,ny});
			}
		}
		
	}
	
}

void bfs(int x,int y)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	visited[x][y] = 1;
	roomSizes[roomCnt] = 1;
	room[x][y] = roomCnt;
	
	int cx = 0;
	int cy = 0;
	int cnt = 1;
	while(!q.empty())
	{
		cx = q.front().first;
		cy = cy = q.front().second;
		q.pop();
		
		for(int i = 0; i<4;i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(visited[nx][ny])
				continue;
			
			if(nx<0||ny<0||nx>=N||ny>=M)
				continue;
			
			if(map[cx][cy]&(1<<i))
				continue;
				
			cnt++;
			visited[nx][ny] = 1;
			room[nx][ny] = roomCnt;
			q.push({nx,ny});
		}
		
	}
	
	roomSizes[roomCnt] = cnt;
	maxRoomSize = max(roomSizes[roomCnt],maxRoomSize);
	
}

int main() {

	cin>>N>>M;
	for(int y = 0;y<M;y++)
	{
		for(int x = 0;x<N;x++)
		{
			cin>>map[x][y];
		}
	}
	
	for(int y = 0;y<M;y++)
	{
		for(int x = 0;x<N;x++)
		{
			if(visited[x][y])
				continue;
				
			roomCnt++;
			bfs(x,y);
		}
	}
	
	memset(visited,0,sizeof(visited));

	for(int y = 0;y<M;y++)
	{
		for(int x = 0;x<N;x++)
		{
			if(visited[x][y])
				continue;
				
			findMaxMergeRoomSize(x,y,room[x][y]);
		}
	}
	
	cout<<roomCnt<<'\n'<<maxRoomSize<<'\n'<<maxMergeRoomSize;
	return 0;
}