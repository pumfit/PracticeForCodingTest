/*
카카오프렌즈 컬러링북
2017 카카오코드 예선

문제
https://programmers.co.kr/learn/courses/30/lessons/1829

풀이 및 공부
https://maybemine.tistory.com/entry/kakaoprogrammers-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%B9%B4%EC%B9%B4%EC%98%A4-%EA%B8%B0%EC%B6%9C-1%EB%8B%A8%EA%B3%84-%ED%92%80%EC%9D%B4-%EB%AA%A8%EC%9D%8C

*프로그래머스에서는 전역변수를 사용하는 경우 solution함수내에서 초기화를 필수적으로 해야한다. 
*/
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int visited[101][101] = { 0, };
vector<vector<int>> map;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int M, N;

int bfs(int y, int x)
{
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[y][x] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i]; int ny = y + dy[i];
			if (nx < 0 || ny < 0 || M <= ny || N <= nx)
				continue;
			if (visited[ny][nx] == 1)
				continue;
			if (map[y][x] != map[ny][nx])
				continue;
			visited[ny][nx] = 1;
			q.push(make_pair(nx, ny));
			cnt++;
		}
	}
	return cnt;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	memset(visited, 0, sizeof(visited));
	dx[0] = 0; dx[1] = 0; dx[2] = 1; dx[3] = -1;
	dy[0] = 1; dy[1] = -1; dy[2] = 0; dy[3] = 0;
	map = picture;
	M = m; N = n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0 && picture[i][j] != 0)
			{
				int area = bfs(i, j);
				number_of_area++;
				max_size_of_one_area = max(area, max_size_of_one_area);
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}