/*
14716 현수막

혁진이는 우선 현수막에서 글자인 부분은 1, 글자가 아닌 부분은 0으로 바꾸는 필터를 적용하여 값을 만드는데 성공했다.
이 값을 바탕으로 글자인 부분 1이 상, 하, 좌, 우, 대각선으로 인접하여 서로 연결되어 있다면 한 개의 글자라고 생각만 하였다.
혁진이가 필터를 적용하여 만든 값이 입력으로 주어졌을 때, 혁진이의 생각대로 프로그램을 구현하면 글자의 개수가 몇 개인지 출력하여라.

입력
첫 번째 줄에는 현수막의 크기인 M와 N가 주어진다. (1 ≤ M, N ≤ 250)
두 번째 줄부터 M+1 번째 줄까지 현수막의 정보가 1과 0으로 주어지며, 1과 0을 제외한 입력은 주어지지 않는다.

혁진이의 생각대로 프로그램을 구현했을 때, 현수막에서 글자의 개수가 몇 개인지 출력하여라.

dfs로 풀이했는데 해당 풀이를 풀고 채점해보니 20ms으로 다른 풀이들 보다 속도가 느린편이라 다른 답을 살펴보았다.
먼저 dfs에서 visited를 따로 지정하지않고 map에 cnt를 넣어 메모리를 줄이고 단계를 줄이는 방법과
bfs로 푸는 방식들이 눈에 띄게 속도가 빨라졌음을 알 수 있었다.
*/
#include <iostream>
using namespace std;

int M, N;
int cnt = 0;
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
int map[251][251] = { 0, };
int visited[251][251] = { 0, };

void dfs(int y, int x)
{
	for (int i = 0; i < 8; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx >= 0 && ny >= 0 && nx < N&&ny < M&&visited[ny][nx] == 0 && map[ny][nx] == 1)
		{
			visited[ny][nx] = 1;
			dfs(ny, nx);
		}
	}
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && visited[i][j] == 0)
			{
				visited[i][j] = 1;
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}