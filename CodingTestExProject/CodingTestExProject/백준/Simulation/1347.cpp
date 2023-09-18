/*
1347 미로 만들기

dx,dy값을 몇번씩 틀려서 이상했던 문제 출력  범위를 어떻게 구할까 고민하다가 매번 그 범위가 최소,최대인지 확인하는 방식으로 풀었다.
이전에 한번 틀렸던 문제라 그런지 빨리 풀 수 있었다.

https://www.acmicpc.net/problem/1347
*/
#include <iostream>
#include <algorithm>
using namespace std;

char map[101][101];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int N;
string s;

int main() {
	cin >> N >> s;
	int minX = 50, minY = 50, maxX = 50, maxY = 50;
	int x = 50; int y = 50;
	int idx = 0;
	map[x][y] = '.';
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'R')
		{
			idx = (idx + 1) % 4;
		}
		else if (s[i] == 'L')
		{
			idx = (idx + 3) % 4;
		}
		else if (s[i] == 'F')
		{
			x = x + dx[idx];
			y = y + dy[idx];
			map[y][x] = '.';
			minX = min(x, minX);
			minY = min(y, minY);
			maxX = max(x, maxX);
			maxY = max(y, maxY);
		}
	}
	for (int i = minY; i <= maxY; i++)
	{
		for (int j = minX; j <= maxX; j++)
		{
			if (map[i][j] != '.')
				cout << '#';
			else
				cout << map[i][j];
		}
		cout << '\n';
	}
	return 0;
}