/*
18430 무기 공학

공학자 길동이는 외부의 침략으로부터 마을을 지킬 수 있는 부메랑 무기를 개발하는 공학자다.
길동이는 부메랑 제작을 위한 고급 나무 재료를 구했다. 이 나무 재료는 NxM크기의 직사각형 형태이며 나무 재료의 부위마다 그 강도가 조금씩 다르다.

나무 재료의 형태와 각 칸의 강도가 주어졌을 때, 길동이가 만들 수 있는 부메랑들의 강도 합의 최댓값을 출력하는 프로그램을 작성하시오.

처음에 부메랑을 하나만 만드는 줄알았는데 전체를 구하는 문제라 백트래킹 방식으로 풀어야한다.
정석적인 백트래킹 문제이고 dfs를 이용하는 문제인데 처음 풀어봐서 접근법이 조금 어려웠다.
이해는 한번 풀어보니까 쉽게 어떻게 풀어야할지 감이 와서 해당 유형의 문제를 몇개 더 풀어 보면 좋을 것 같다.

특히 방문시에 dfs처럼 for문을 사용하면 다시 되돌아 올 수 가 없어서 각 경우에 대해 if문으로 처리하는 것을 유의깊게 생각해야한다.
*/
#include <iostream>
using namespace std;

int N, M;
int map[101][101] = { 0, };
int visited[101][101] = { 0, };
int intensity = 0;
void check(int y, int x, int sum)
{
	if (x == M)
	{
		x = 0;
		y++; //한칸 아래로 이동
	}
	if (y == N)
	{
		intensity = max(intensity, sum);
		return;
	}
	if (!visited[y][x])
	{
		if (y - 1 >= 0 && x - 1 >= 0 && !visited[y - 1][x] && !visited[y][x - 1])
		{
			visited[y][x] = 1; visited[y - 1][x] = 1; visited[y][x - 1] = 1;
			int temp = sum + map[y][x] * 2 + map[y - 1][x] + map[y][x - 1];
			check(y, x + 1, temp);
			visited[y][x] = 0; visited[y - 1][x] = 0; visited[y][x - 1] = 0;
		}
		if (x - 1 >= 0 && y + 1 < N && !visited[y][x - 1] && !visited[y + 1][x])
		{
			visited[y][x] = 1; visited[y][x - 1] = 1; visited[y + 1][x] = 1;
			int temp = sum + map[y][x] * 2 + map[y][x - 1] + map[y + 1][x];
			check(y, x + 1, temp);
			visited[y][x] = 0; visited[y][x - 1] = 0; visited[y + 1][x] = 0;
		}
		if (x + 1 < M&&y + 1 < N && !visited[y][x + 1] && !visited[y + 1][x])
		{
			visited[y][x] = 1; visited[y][x + 1] = 1; visited[y + 1][x] = 1;
			int temp = sum + map[y][x] * 2 + map[y][x + 1] + map[y + 1][x];
			check(y, x + 1, temp);
			visited[y][x] = 0; visited[y][x + 1] = 0; visited[y + 1][x] = 0;
		}
		if (x + 1 < M&&y - 1 >= 0 && !visited[y][x + 1] && !visited[y - 1][x])
		{
			visited[y][x] = 1; visited[y][x + 1] = 1; visited[y - 1][x] = 1;
			int temp = sum + map[y][x] * 2 + map[y][x + 1] + map[y - 1][x];
			check(y, x + 1, temp);
			visited[y][x] = 0; visited[y][x + 1] = 0; visited[y - 1][x] = 0;
		}
	}
	check(y, x + 1, sum);//방문하고 넘어가지 않는 경우
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	check(0, 0, 0);
	cout << intensity;
	return 0;
}