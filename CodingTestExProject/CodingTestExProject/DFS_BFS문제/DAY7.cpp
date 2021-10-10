/*
16948 데스 나이트

게임을 좋아하는 큐브러버는 체스에서 사용할 새로운 말 "데스 나이트"를 만들었다.
데스 나이트가 있는 곳이 (r, c)라면, (r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)로 이동할 수 있다.
크기가 N×N인 체스판과 두 칸 (r1, c1), (r2, c2)가 주어진다. 
데스 나이트가 (r1, c1)에서 (r2, c2)로 이동하는 최소 이동 횟수를 구해보자. 체스판의 행과 열은 0번부터 시작한다.

데스 나이트는 체스판 밖으로 벗어날 수 없다.

첫째 줄에 체스판의 크기 N(5 ≤ N ≤ 200)이 주어진다. 둘째 줄에 r1, c1, r2, c2가 주어진다.

첫째 줄에 데스 나이트가 (r1, c1)에서 (r2, c2)로 이동하는 최소 이동 횟수를 출력한다. 이동할 수 없는 경우에는 -1을 출력한다.

한번에 맞출 수 있다!!하고 도전한 문제인데 생각보다 오래걸렸다.
이유는 max값을 따로 변수로 구하려고 했던 점이랑
return 해야 할 부분을 생각하지 못해서 였다.
아래와 같은 풀이로 푸는 경우 0 즉 답이 없는 경우에 출력값이 -1이 되어 따로 예외처리를 해줄 필요가 없다.
큐에 pair넣는 것 계속 연습했더니 많이 익숙해졌다. 또한 비슷한 유형의 문제가 많다보니 빠르게 익숙해 진 것 같다.
*/
#include <iostream>
#include <queue>
using namespace std;

int map[201][201] = { 0, };
int visited[201][201] = { 0, };
int N;
int ax, ay, bx, by;
//(r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)
int dx[6] = { -2,-2,0,0,2,2 };
int dy[6] = { -1,1,-2,2,-1,1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		if (x == bx && y == by)
			return;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N&&ny >= 0 && ny < N&&visited[nx][ny] == 0)
			{
				visited[nx][ny] = visited[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	cin >> N >> ax >> ay >> bx >> by;
	bfs(ax, ay);
	cout << visited[bx][by] - 1;
	return 0;
}