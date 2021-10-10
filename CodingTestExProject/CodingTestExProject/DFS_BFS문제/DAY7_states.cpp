/*
7576 �丶��

������ Ǯ�� Ǯ�̸� ���� �����ϰ� Ǯ��

â�� �����Ǵ� �丶��� �߿��� �� ���� �͵� ������, 
���� ���� ���� �丶��鵵 ���� �� �ִ�. ���� �� �Ϸ簡 ������, 
���� �丶����� ������ ���� �ִ� ���� ���� �丶����� ���� �丶���� ������ �޾� �Ͱ� �ȴ�. 
�ϳ��� �丶���� ������ ���� ����, ������, ��, �� �� ���⿡ �ִ� �丶�並 �ǹ��Ѵ�. ��
���� ���⿡ �ִ� �丶��鿡�Դ� ������ ���� ���ϸ�, �丶�䰡 ȥ�� ������ �ʹ� ���� ���ٰ� �����Ѵ�. 
ö���� â�� ������ �丶����� ��ĥ�� ������ �� �Ͱ� �Ǵ���, �� �ּ� �ϼ��� �˰� �;� �Ѵ�.

�丶�並 â�� �����ϴ� ���ڸ���� ���ڵ��� ũ��� ���� �丶���� ���� ���� �丶����� ������ �־����� ��, 
��ĥ�� ������ �丶����� ��� �ʹ���, �� �ּ� �ϼ��� ���ϴ� ���α׷��� �ۼ��϶�. 
��, ������ �Ϻ� ĭ���� �丶�䰡 ������� ���� ���� �ִ�.

" ����, ������, ��, �� �� ����","�丶����� ��� �ʹ���, �� �ּ� �ϼ�","���� 1�� ���� �丶��, ���� 0�� ���� ���� �丶��, ���� -1�� �丶�䰡 ������� ���� ĭ�� ��Ÿ����."
�� ���� �ֿ� ������ �� ĳġ�ؾ� �Ѵ�.

M,N �������� ���� �ʹݿ� ��û �򰥸�����
����!! 2���� ���� Ʋ��������  M : ������ x ,N : ������ y ,map[y][x]

void printMap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout<<visited[i][j]<<" ";
		}
		cout << endl;
	}
}

Ǯ�� ���� map�� visited ��ü�� �ᵵ �ȴٴ� ����� �ٸ� Ǯ�̸� ���� ���޾Ҵ�.
�׷��� Ǯ��83�� ���� �ݺ����� ��� �ȴ�. �׷��� �ش� Ǯ�̷� �޸𸮴� �ٿ����� �ð��� �� �þ���.
*/
#include<iostream>
#include<queue>
using namespace std;

int M, N;
int visited[1001][1001] = { 0, };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == 0)
			{
				visited[nx][ny] = visited[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main()
{
	int min = 0;
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int K;
			cin >> K;
			visited[i][j] = K;
			if (visited[i][j] == 1)
			{
				q.push(make_pair(i, j));
			}
		}
	}
	bfs();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			if (min < visited[i][j])
				min = visited[i][j];
		}
	}
	cout << min-1;
}
/*
#include<iostream>
#include<queue>
using namespace std;

int M, N;
int map[1001][1001] = { 0, };
int visited[1001][1001] = { 0, };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == 0)
			{
				visited[nx][ny] = visited[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main()
{
	int min = 0;
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int K;
			cin >> K;
			map[i][j] = K;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1)
			{
				q.push(make_pair(i, j));
				visited[i][j] = 1;
			}
			else if (map[i][j] == -1)
			{
				visited[i][j] = -1;
			}
		}
	}
	bfs();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			if (min < visited[i][j])
				min = visited[i][j];
		}
	}
	cout << min-1;
}
*/