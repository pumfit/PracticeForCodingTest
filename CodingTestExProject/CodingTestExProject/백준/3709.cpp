/*
3709  ���������� ����

�ùķ��̼� �������� ȸ���� �ϴ� ����� ���� �� �ִ� ����
ȸ�� ���⿡ �°� dx,dy�������ְ�
ȸ���ؾ��ϴ� �κп��� %�����ڸ� ���� �ٲ��ִ� �����̴�.

���������� ���� ���̰� dfs�� ��� Ž���ϴ� ���ǿ� ���� ������ �Ǵ¹����̴�.

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
	if (map[x][y] == 1) {//�ſ��� ���� ��� ���������� 
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