/*
2636 치즈

아래 <그림 1>과 같이 정사각형 칸들로 이루어진 사각형 모양의 판이 있고, 그 위에 얇은 치즈(회색으로 표시된 부분)가 놓여 있다. 판의 가장자리(<그림 1>에서 네모 칸에 X친 부분)에는 치즈가 놓여 있지 않으며 치즈에는 하나 이상의 구멍이 있을 수 있다.

이 치즈를 공기 중에 놓으면 녹게 되는데 공기와 접촉된 칸은 한 시간이 지나면 녹아 없어진다. 치즈의 구멍 속에는 공기가 없지만 구멍을 둘러싼 치즈가 녹아서 구멍이 열리면 구멍 속으로 공기가 들어가게 된다. <그림 1>의 경우, 치즈의 구멍을 둘러싼 치즈는 녹지 않고 ‘c’로 표시된 부분만
한 시간 후에 녹아 없어져서 <그림 2>와 같이 된다.

입력으로 사각형 모양의 판의 크기와 한 조각의 치즈가 판 위에 주어졌을 때, 공기 중에서 치즈가 모두 녹아 없어지는 데 걸리는 시간과 
모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수를 구하는 프로그램을 작성하시오.

100퍼센트에서 왜맞틀 이슈로 한 시간정도 고민했던 것 같다..0으로만 이뤄진경우 0 0 이 나와야하는데 카운트가 나오는 문제랑
이전 값 기억하는 것 처리가 조금 늦었다. 좀 더 깔끔하게 풀 수 있을 것 같아서 아쉽
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int Y, X;
int map[101][101];
int visited[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt = 0, remain = 0;

int CountRemain()
{
	int sum = 0;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (map[i][j] == 1)
				sum++;
		}
	}
	return sum;
}

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[y][x] = 1;
	cnt++;
	while (!q.empty())
	{
		int sx = q.front().first;
		int sy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if (nx < 0 || ny < 0 || nx >= X || ny >= Y)
				continue;
			if (visited[ny][nx] == 0 && map[ny][nx] == 0)
			{
				q.push(make_pair(nx, ny));

			}
			else
			{
				map[ny][nx] = 0;
			}
			visited[ny][nx] = 1;
		}
	}
}

int main()
{
	cin >> Y >> X;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cin >> map[i][j];
		}
	}
	while (true)
	{
		int count = 0;
		count = CountRemain();
		bfs(0, 0);
		if (count == 0)
			break;
		memset(visited, 0, sizeof(visited));
		remain = count;
	}

	cout << cnt - 1 << endl;
	cout << remain;
	return 0;
}