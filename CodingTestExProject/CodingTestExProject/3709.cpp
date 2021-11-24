/*
3709  레이저빔은 어디로

시뮬레이션 문제에서 회전을 하는 방법을 익힐 수 있는 문제
회전 방향에 맞게 dx,dy설정해주고
회전해야하는 부분에서 %연산자를 통해 바꿔주는 문제이다.

구현문제중 쉬운 편이고 dfs로 모두 탐색하다 조건에 빠져 나오면 되는문제이다.

*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int T, N, R;
int map[52][52];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

void simulation(int x, int y, int dir)
{
	if (y == 0 || x == 0 || y == N + 1 || x == N + 1) {
		cout << x << " " << y << '\n';
		return;
	}
	if (map[x][y] == 1) {//거울을 만난 경우 오른쪽으로 
		int nd = (dir + 1) % 4;
		simulation(x + dx[nd], y + dy[nd], nd);
	}
	else
	{
		simulation(x + dx[dir], y + dy[dir], dir);
	}


}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		memset(map, 0, sizeof(map));
		cin >> N >> R;
		int sx, sy;
		for (int j = 0; j < R; j++)
		{
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}
		cin >> sx >> sy;
		if (sy == 0)
			simulation(sx, sy + 1, 2);
		else if (sy == N + 1)
			simulation(sx, sy - 1, 0);
		else if (sx == 0)
			simulation(sx + 1, sy, 3);
		else if (sx == N + 1)
			simulation(sx - 1, sy, 1);
	}

	return 0;
}