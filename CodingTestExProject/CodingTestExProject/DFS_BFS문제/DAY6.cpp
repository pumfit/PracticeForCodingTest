/*
DAY6 1697 숨바꼭질

수빈이는 동생과 숨바꼭질을 하고 있다.
수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

"가장 빠른 시간"이므로 bfs로 구현하였다.
단계를 구하는 방법을 visited를 int형으로 구현하여 더하는 방식으로 하였다. 그리고 출력시에 첫 출발점을 1로 지정했으므로
-1을 해 답을 출력한다.
*/
#include <iostream>
#include <queue>
using namespace std;

int N, K;
int sec = 0;
bool isClear = false;
int visited[200001] = { 0, };

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			int y = 0;
			if (i == 0)
			{
				y = x - 1;
			}
			else if (i == 1)
			{
				y = x + 1;
			}
			else
			{
				y = 2 * x;
			}
			if (y >= 0 && y <= 100000 && !visited[y])
			{
				q.push(y);
				visited[y] = 1 + visited[x];
				if (y == K)
					isClear = true;
			}
		}

		if (isClear)
			break;
	}
}

int main() {
	cin >> N >> K;
	bfs(N);
	cout << visited[K] - 1;
	return 0;
}