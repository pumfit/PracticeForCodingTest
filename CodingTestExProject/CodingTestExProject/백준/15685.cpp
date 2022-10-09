/*
15685 드래곤 커브

규칙성 찾는게 너무 어려웠던 문제이다.
풀이 당시 화살표를 보면서 규칙성을 찾고자 했는데 인덱스로 보고 찾았으면 좀 더 쉽게 찾지 않았을까 생각이 들었다.

규칙은 90도 회전 이후 진행방향은 "이전 세대의 +1 % 4 로 진행된다."는 점이다.

처음엔 이 규칙이 첫번째 이후에만 적용되는 줄 알았는데 첫 배열부터 적용된다는 점을 뒤늦게 알게되었다.
저 규칙만 찾는다면 이후는 구현만 잘해내면 되는 문제
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

	// 0 세대
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
		for (int j = 0; j < size; j++) // 세대 만큼 진행
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