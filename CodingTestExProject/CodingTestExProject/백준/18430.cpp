/*
18430 ���� ����

������ �浿�̴� �ܺ��� ħ�����κ��� ������ ��ų �� �ִ� �θ޶� ���⸦ �����ϴ� �����ڴ�.
�浿�̴� �θ޶� ������ ���� ��� ���� ��Ḧ ���ߴ�. �� ���� ���� NxMũ���� ���簢�� �����̸� ���� ����� �������� �� ������ ���ݾ� �ٸ���.

���� ����� ���¿� �� ĭ�� ������ �־����� ��, �浿�̰� ���� �� �ִ� �θ޶����� ���� ���� �ִ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

ó���� �θ޶��� �ϳ��� ����� �پ˾Ҵµ� ��ü�� ���ϴ� ������ ��Ʈ��ŷ ������� Ǯ����Ѵ�.
�������� ��Ʈ��ŷ �����̰� dfs�� �̿��ϴ� �����ε� ó�� Ǯ����� ���ٹ��� ���� �������.
���ش� �ѹ� Ǯ��ϱ� ���� ��� Ǯ������� ���� �ͼ� �ش� ������ ������ � �� Ǯ�� ���� ���� �� ����.

Ư�� �湮�ÿ� dfsó�� for���� ����ϸ� �ٽ� �ǵ��� �� �� �� ��� �� ��쿡 ���� if������ ó���ϴ� ���� ���Ǳ�� �����ؾ��Ѵ�.
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
		y++; //��ĭ �Ʒ��� �̵�
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
	check(y, x + 1, sum);//�湮�ϰ� �Ѿ�� �ʴ� ���
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