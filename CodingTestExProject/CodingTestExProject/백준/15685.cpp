/*
15685 �巡�� Ŀ��

��Ģ�� ã�°� �ʹ� ������� �����̴�.
Ǯ�� ��� ȭ��ǥ�� ���鼭 ��Ģ���� ã���� �ߴµ� �ε����� ���� ã������ �� �� ���� ã�� �ʾ����� ������ �����.

��Ģ�� 90�� ȸ�� ���� ��������� "���� ������ +1 % 4 �� ����ȴ�."�� ���̴�.

ó���� �� ��Ģ�� ù��° ���Ŀ��� ����Ǵ� �� �˾Ҵµ� ù �迭���� ����ȴٴ� ���� �ڴʰ� �˰ԵǾ���.
�� ��Ģ�� ã�´ٸ� ���Ĵ� ������ ���س��� �Ǵ� ����
*/
#include <iostream>
#include <vector>
using namespace std;

int map[101][101] = { 0, };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

void curve(int x, int y, int d, int g)
{

	int nx, ny;
	vector<int> v;
	v.push_back(d);

	// 0 ����
	map[x][y] = 1;
	nx = x + dx[d]; ny = y + dy[d];
	map[nx][ny] = 1;
	x = nx; y = ny;

	//for (int i = 0; i < v.size(); i++)
	//	cout << v[i] << " ";

	cout << endl;
	for (int i = 1; i <= g; i++)
	{
		int size = v.size();
		vector<int> cur;
		for (int j = 0; j < size; j++) // ���� ��ŭ ����
		{
			d = (v[size - (j + 1)] + 1) % 4 == 4 ? 0 : (v[size - (j + 1)] + 1) % 4;
			v.push_back(d);
			nx = x + dx[d]; ny = y + dy[d];
			map[nx][ny] = 1;
			x = nx; y = ny;
		}
		//for (int i = 0; i < v.size(); i++)
		//	cout << v[i] << " ";
		//cout << endl;
	}

}

int main() {
	int N;
	int answer = 0;
	cin >> N;
	int x, y, d, g;
	while (N--)
	{
		cin >> x >> y >> d >> g;
		curve(x, y, d, g);
		//cout << endl;
	}
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
				answer++;
		}
	}

	cout << answer;
	return 0;
}