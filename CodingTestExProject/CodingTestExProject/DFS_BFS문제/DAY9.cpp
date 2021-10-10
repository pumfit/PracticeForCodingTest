/*
로봇청소기

구현후 틀렸는데 어디서 틀렸는지 너무 막막함..
			if (isAvailable(nx, ny) && !visited[nx][ny] && map[nx][ny] == 0)
			{
				q.push(make_pair(nx,ny));
				d = (d + 3 - i) % 4;
				flag = true;
				break;
			}

https://hibee.tistory.com/186
*/

#include<iostream>
#include<queue>
using namespace std;

struct robot {
	int x, y, dir;

	robot() { }
	robot(int _x, int _y, int _dir) : x(_x), y(_y), dir(_dir) { }
};

int N, M;//세로 , 가로 
int map[51][51] = {0,};//벽 1 빈칸 0
int visited[51][51] = { 0, };
int cnt = 0;
robot s;
int x, y, d;

int dx[4] = { -1,0,1,0 };
int dy[4] = {0,1,0,-1};//북남서동

int changeDir(int dir) {
	if (dir == 0) return 3;
	else if (dir == 3) return 2;
	else if (dir == 2) return 1;
	else return 0;
}

bool isAvailable(int x, int y)
{
	return (x >= 0 && y >= 0 && x < N && y < M) ? true : false;
}

void printMap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << visited[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}

void bfs()
{
	queue<robot> q;
	q.push(s);

	while (!q.empty())
	{

		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		q.pop();

		if (!visited[x][y])
		{
			visited[x][y] = true;
			cnt++;
			//printMap();
		}
		
		bool flag = false;
		int nd = dir;
		for (int i = 0; i < 4; i++)
		{
			nd = changeDir(nd);

			int nx = x + dx[nd];
			int ny = y + dy[nd];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny]==1) continue;

			q.push(robot(nx,ny,nd));
			flag = true;
			break;
			
		}
		if (!flag)
		{
			int bd = (dir + 2) % 4;

			int nx = x + dx[bd];
			int ny = y + dy[bd];
			
			if (nx < 0 || ny < 0 || nx > N || ny >= M) continue;

			if (map[nx][ny] != 1)//후진 가능
			{
				q.push(robot(nx,ny,dir));
				continue;
			}
			else//후진 불가
			{
				return;
			}
		}
	}
}

int main()
{
	cin >> N >> M >> x >> y >> d;
	s.x = x; s.y = y; s.dir = d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	bfs();
	cout << cnt;
	return 0;
}