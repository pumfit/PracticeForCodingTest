/*

2583 영역 구하기

dfs

너무 늦게 푼 문제..발전이 없구나 흑흑 보자마자 dfs로 풀면되겠다 생각했고 막힌 부분은 아래로

1.채워진 영역

(0,0)좌표에서 뒤집어져 있는 모양인데 이는 영역을 구하는 것이니 상관없고 모양만 같으면 된다.
그런데 처음에 입력되는 좌표를 이해를 못해서 두번째값에서 빼고 더하고 난리가 났었다. 출력해보고 비교해가면서 겨우 찾았다.

2.dfs로 영역개수를 어떻게 구하지..?

여러번 했던 건데 까먹어버려서 해맸던 부분 bfs 리턴값을 int로 해서 bfs마다 1씩 더한 값을 리턴하도록 했더니 단계별로 합이 나와서
뭐지 했다. 함수를 부를때마다 더해줘야하니 함수 초반에 값을 더해서 구해주면 된다. 왜 간단한건 매번 생각이 안나는 건지 모르겠다.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int M, N;
int c = 0;
int map[101][101] = { 0, };
int visited[101][101] = { 0, };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool IsInside(int x, int y)
{
	return (x < N&&x >= 0 && y < M&&y >= 0);
}

void dfs(int x, int y)
{
	c++;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (IsInside(nx, ny) && visited[ny][nx] == 0)
		{
			visited[ny][nx] = 1;
			dfs(nx, ny);
		}
	}
}

void print()
{
	for (int i = 0; i < M; i++)//y
	{
		for (int j = 0; j < N; j++)//x
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int K;
	vector<int> v;
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y, nx, ny;
		cin >> x >> y >> nx >> ny;
		for (int j = x; j < nx; j++)
		{
			for (int k = y; k < ny; k++)
			{
				visited[k][j] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++)//y
	{
		for (int j = 0; j < N; j++)//x
		{
			if (visited[i][j] == 0)
			{
				visited[i][j] = 1;
				dfs(j, i);
				v.push_back(c);
				c = 0;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}