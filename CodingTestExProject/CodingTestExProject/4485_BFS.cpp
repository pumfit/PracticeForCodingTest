/*
4485 녹색 옷 입은 애가 젤다지?

젤다의 전설 게임에서 화폐의 단위는 루피(rupee)다. 그런데 간혹 '도둑루피'라 불리는 검정색 루피도 존재하는데, 이걸 획득하면 오히려 소지한 루피가 감소하게 된다!
젤다의 전설 시리즈의 주인공, 링크는 지금 도둑루피만 가득한 N x N 크기의 동굴의 제일 왼쪽 위에 있다. [0][0]번 칸이기도 하다. 왜 이런 곳에 들어왔냐고 묻는다면 밖에서 사람들이 자꾸 "젤다의 전설에 나오는 녹색 애가 젤다지?"라고 물어봤기 때문이다. 링크가 녹색 옷을 입은 주인공이고 젤다는 그냥 잡혀있는 공주인데, 게임 타이틀에 젤다가 나와있다고 자꾸 사람들이 이렇게 착각하니까 정신병에 걸릴 위기에 놓인 것이다.
하여튼 젤다...아니 링크는 이 동굴의 반대편 출구, 제일 오른쪽 아래 칸인 [N-1][N-1]까지 이동해야 한다. 동굴의 각 칸마다 도둑루피가 있는데, 이 칸을 지나면 해당 도둑루피의 크기만큼 소지금을 잃게 된다. 링크는 잃는 금액을 최소로 하여 동굴 건너편까지 이동해야 하며, 한 번에 상하좌우 인접한 곳으로 1칸씩 이동할 수 있다.
링크가 잃을 수밖에 없는 최소 금액은 얼마일까?

좋아하는 게임유머라서 재밌게 풀었다

bfs풀이

bfs에서 어떻게 최소값을 판단하는가??가 주요 포인트였던 문제이다.
visited 풀어두고 전체탐색으로 변경될 visited 기존값보다 최소가 되는 경우에만 이동이 가능하도록 한다.
+)이 문제는 꼭 이후에 다익스트라 알고리즘으로 다시 풀어보기!
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N;
int map[126][126] = { 0, };
int visited[126][126] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool CheckInside(int x, int y)
{
	return (x < N&&y < N&&x >= 0 && y >= 0) ? true : false;
}

void bfs(int sx, int sy)
{
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (CheckInside(nx, ny))//전체탐색
			{
				if (visited[nx][ny] > visited[x][y] + map[nx][ny])//기존하고 비교
				{
					visited[nx][ny] = visited[x][y] + map[nx][ny];
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	int k = 0;
	while (true)
	{
		k++;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
				visited[i][j] = 1250;
			}
		}
		if (N == 0)
			return 0;
		else
		{
			visited[0][0] = map[0][0];
			bfs(0, 0);
			cout << "Problem " << k << ": " << visited[N - 1][N - 1] << endl;
		}
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}