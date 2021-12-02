/*
3187 양치기 꿍

양치기 꿍은 맨날 늑대가 나타났다고 마을 사람들을 속였지만 이젠 더이상 마을 사람들이 속지 않는다. 화가 난 꿍은 복수심에 불타 아예 늑대들을 양들이 있는 울타리안에 마구 집어넣어 양들을 잡아먹게 했다.
하지만 양들은 보통 양들이 아니다. 같은 울타리 영역 안의 양들의 숫자가 늑대의 숫자보다 더 많을 경우 늑대가 전부 잡아먹힌다. 물론 그 외의 경우는 양이 전부 잡아먹히겠지만 말이다.
꿍은 워낙 똑똑했기 때문에 이들의 결과는 이미 알고있다. 만약 빈 공간을 '.'(점)으로 나타내고 울타리를 '#', 늑대를 'v', 양을 'k'라고 나타낸다면 여러분은 몇 마리의 양과 늑대가 살아남을지 계산할 수 있겠는가?
단, 울타리로 막히지 않은 영역에는 양과 늑대가 없으며 양과 늑대는 대각선으로 이동할 수 없다.

쉬운 완전탐색 문제이고 풀이방식은 맞는데 자꾸 이상한 실수로 푸는데 늦어졌다.
한번에 통과하긴 했지만 몇가지 실수들을 줄이고자 기록한다.
계속 0 0이 나와서 보니 R,C를 받지않고 테케를 돌렸다거나 map에서 양,늑대 체크를 해야하는데 visited를 체크한다거나 등등 실수가 많았다.
코드 치면서 계속 생각하면서 푸는 습관을 길러야겠다는 생각이 들었다.
*/
#include <iostream>
using namespace std;

int R, C;
char map[251][251] = { 0, };
int visited[251][251] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int sheep = 0, wolf = 0;

void dfs(int y, int x)
{
	visited[y][x] = 1;
	if (map[y][x] == 'v')
		wolf++;
	if (map[y][x] == 'k')
		sheep++;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < C&&ny < R&&visited[ny][nx] == 0 && map[ny][nx] != '#')
		{
			dfs(ny, nx);
		}
	}
}
int main() {
	int K = 0, V = 0;
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (visited[i][j] == 0 && map[i][j] != '#')
			{
				dfs(i, j);
				K += sheep > wolf ? sheep : 0;
				V += sheep > wolf ? 0 : wolf;
				sheep = 0; wolf = 0;

			}
		}
	}
	cout << K << " " << V;
	return 0;
}