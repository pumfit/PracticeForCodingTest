/*
7576 토마토

문제를 풀때 풀이를 먼저 생각하고 풀자

창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 
아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 
익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 
하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대
각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 
철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 
며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 
단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

" 왼쪽, 오른쪽, 앞, 뒤 네 방향","토마토들이 모두 익는지, 그 최소 일수","정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다."
와 같은 주요 정보를 잘 캐치해야 한다.

M,N 범위에서 부터 초반에 엄청 헷갈린문제
제발!! 2차원 범위 틀리지말자  M : 가로축 x ,N : 세로축 y ,map[y][x]

void printMap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout<<visited[i][j]<<" ";
		}
		cout << endl;
	}
}

풀고 나서 map을 visited 자체로 써도 된다는 사실을 다른 풀이를 보고 깨달았다.
그렇게 풀면83번 라인 반복문은 없어도 된다. 그런데 해당 풀이로 메모리는 줄였지만 시간은 더 늘었다.
*/
#include<iostream>
#include<queue>
using namespace std;

int M, N;
int visited[1001][1001] = { 0, };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == 0)
			{
				visited[nx][ny] = visited[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main()
{
	int min = 0;
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int K;
			cin >> K;
			visited[i][j] = K;
			if (visited[i][j] == 1)
			{
				q.push(make_pair(i, j));
			}
		}
	}
	bfs();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			if (min < visited[i][j])
				min = visited[i][j];
		}
	}
	cout << min-1;
}
/*
#include<iostream>
#include<queue>
using namespace std;

int M, N;
int map[1001][1001] = { 0, };
int visited[1001][1001] = { 0, };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == 0)
			{
				visited[nx][ny] = visited[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main()
{
	int min = 0;
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int K;
			cin >> K;
			map[i][j] = K;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1)
			{
				q.push(make_pair(i, j));
				visited[i][j] = 1;
			}
			else if (map[i][j] == -1)
			{
				visited[i][j] = -1;
			}
		}
	}
	bfs();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			if (min < visited[i][j])
				min = visited[i][j];
		}
	}
	cout << min-1;
}
*/