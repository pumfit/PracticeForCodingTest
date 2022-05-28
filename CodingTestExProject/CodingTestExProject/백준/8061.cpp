/*
8061 Bitmap

There is given a rectangular bitmap of size n x m. Each pixel of the bitmap is either white or black,
but at least one is white. The pixel in i-th line and j-th column is called the pixel (i,j).
The distance between two pixels p1=(i1,j1) and p2=(i2,j2) is defined as:d(p1,p2)=|i1-i2|+|j1-j2|.


dfs로 풀이를 진행한 문제 처음에 생각한 풀이랑 답이 다른게 없었지만 이상한 곳에서 자꾸 실수해서 시간이 꽤 걸렸다.

1.입력
입력에 빈칸이 없어서 string 형태로 받고 다시 int형변환해서 넣어주는 과정이 필요한데 해당 과정없이 cin으로 바로 입력받아서
11111000...과 같이 map에 입력이 들어오는 참사가 벌어졌다. 문제 볼때 입력 조건도 확실하게 확인할 것
2.출력
문제 풀이 후 제출했는데 5퍼대에서 틀려서 왜맞틀 하면서 테케 더 넣어보고 있었는데...출력을 보니 출력은 또 값사이 공백을 넣어준다.
이를 추가하니 통과했다. 위와 같이 역시 출력 조건도 확실히 확인할 것

*/
#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int map[183][183] = { 0, };
int visited[183][183] = { 0, };
int Y, X;

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < X&&ny < Y&&map[ny][nx] != 1)
			{
				if (visited[ny][nx] == 0)
				{
					visited[ny][nx] = visited[y][x] + 1;
					q.push(make_pair(nx, ny));
				}
				else if (visited[ny][nx] > visited[y][x] + 1)
				{
					visited[ny][nx] = visited[y][x] + 1;
					q.push(make_pair(nx, ny));
				}

			}
		}
	}
	return;
}

int main() {
	cin >> Y >> X;
	for (int i = 0; i < Y; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < X; j++)
		{
			map[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (map[i][j] == 1)
			{
				bfs(i, j);
			}
		}
	}
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}