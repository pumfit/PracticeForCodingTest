#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;



char map[25][25];

int visited[25][25];

int dx[4] = { 0,0,1,-1 };

int dy[4] = { 1,-1,0,0 };

int cnt = 0, sum = 0;

int N;

void printMap()

{

	for (int i = 0; i < N; i++)

	{

		string s;

		cin >> s;

		for (int j = 0; j < N; j++)

		{

			cout << visited[i][j];

		}

		cout << endl;

	}

}



void dfs(int x, int y)

{

	visited[x][y] = 1;
	sum++;
	for (int i = 0; i < 4; i++)
	{

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N&&ny >= 0 && ny < N)
		{

			if (map[nx][ny] == '1'&&visited[nx][ny] == 0)
			{

				visited[nx][ny] = cnt;
				dfs(nx, ny);

			}

		}

	}

}



int main() {

	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++)
	{

		string s;
		cin >> s;

		for (int j = 0; j < N; j++)
		{
			map[i][j] = s[j];
		}

	}



	for (int i = 0; i < N; i++)
	{

		for (int j = 0; j < N; j++)
		{

			if (map[i][j] == '1'&&visited[i][j] == 0)
			{

				dfs(i, j);
				cnt++;
				v.push_back(sum);
				sum = 0;

			}

		}

	}

	sort(v.begin(), v.end());

	cout << cnt << endl;

	for (int i = 0; i < v.size(); i++)

	{

		cout << v[i] << endl;

	}

	printMap();



	return 0;

}