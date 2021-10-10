/*
7569 토마토 (3차원)
 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향 문제

 x,y,z 좌표확인이 헷갈려서 조금 어려웠다.
 이전에 했던 문제를 복습하면서 queue<pair<pair<int, int>, int>> q;로 3차원으로
 풀이하는 방법도 알게되었다. 이전에 처음 2차원을 풀었을때 오래걸렸던 것에 비해 쉽게 할 수 있었다.
*/
#include<iostream>
#include<queue>
using namespace std;

int tomatos[101][101][101];
int M, N, H;

int dx[6] = {0,0,1,-1,0,0};
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };

queue<pair<pair<int, int>, int>> q;

bool isAvailable(int x,int y,int z)
{ 
	return (x >= 0 && y >= 0 && z >= 0 && x < M && y < N && z < H)? true : false;
}

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();
		for (int i=0;i<6;i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (isAvailable(nx,ny,nz) && tomatos[nz][ny][nx] == 0)
			{
				tomatos[nz][ny][nx] = tomatos[z][y][x] + 1;//Z Y X
				q.push(make_pair(make_pair(nx, ny), nz));
			}
		}
	}
}

int main()
{
	int days = 0;
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++)//Z
	{
		for (int j = 0; j < N; j++)//Y
		{
			for (int k = 0; k < M; k++)//X
			{
				int n;
				cin >> n;
				tomatos[i][j][k] = n;//Z Y X
				if (n == 1)
					q.push(make_pair(make_pair(k, j),i));//X Y Z
			}
		}
	}
	bfs();
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (tomatos[i][j][k] == 0)
				{
					cout << -1;
					return 0;
				}
				if (days < tomatos[i][j][k])
					days = tomatos[i][j][k];
			}
		}
	}
	cout << days-1;
}