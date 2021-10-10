/*
2178 미로탐색

BFS 최단거리 탐색
*/
#include <iostream>
#include <string>
#include <queue>

using namespace std;



char map[101][101];
int visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M;



void printMap()
{

	for (int i = 0; i < N; i++)
	{

		for (int j = 0; j < M; j++)
		{

			cout << visited[i][j];
		}
		cout << endl;
	}
}

void bfs(int sx, int sy)
{

	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	visited[sx][sy] = 1;

	while (!q.empty())
	{

		int cx = q.front().first;
		int cy = q.front().second;//좌표값

		q.pop();

		for (int i = 0; i < 4; i++)
		{

			int nx = dx[i] + cx;
			int ny = dy[i] + cy;

			if (0 <= nx && nx < N && 0 <= ny && ny < M) // 미로의 범위
			{

				if (map[nx][ny] == '1' && visited[nx][ny] == 0)

				{

					visited[nx][ny] = visited[cx][cy] + 1;

					q.push(make_pair(nx, ny));

				}

			}

		}



	}

}



int main() {



	cin >> N >> M;



	for (int i = 0; i < N; i++)

	{

		string s;

		cin >> s;

		for (int j = 0; j < M; j++)
		{
			map[i][j] = s[j];
		}

	}

	bfs(0, 0);

	printMap();

	cout << visited[N - 1][M - 1];

	return 0;

}