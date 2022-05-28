/*
거리두기 확인하기
2021 카카오 채용연계형 인턴십

문제
https://programmers.co.kr/learn/courses/30/lessons/81302

풀이 및 공부
https://maybemine.tistory.com/entry/kakaoprogrammers-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%B9%B4%EC%B9%B4%EC%98%A4-%EA%B8%B0%EC%B6%9C-1%EB%8B%A8%EA%B3%84-%ED%92%80%EC%9D%B4-%EB%AA%A8%EC%9D%8C

* 작년에 못풀었던 문제 성공!
* 더 짧고 간결하게 어떻게 풀지?
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dx[4] = { 0,0,-2,2 };
int dy[4] = { 2,-2,0,0 };

int ddx[4] = { 0,0,-1,1 };
int ddy[4] = { 1,-1,0,0 };

int dlx[4] = { 1,1,-1,-1 };
int dly[4] = { -1,1,-1,1 };

vector<string> room;

bool checkPerson(int x, int y) {
	for (int i = 0; i < 4; i++)//사람간의 거리가 1인 경우
	{
		int nx = x + ddx[i];
		int ny = y + ddy[i];

		if (nx < 0 || nx >= room[0].size() || ny < 0 || ny >= room.size())
			continue;
		if (room[ny][nx] == 'P')
			return true;
	}
	for (int i = 0; i < 4; i++)//사람간의 거리가 2인 경우
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= room[0].size() || ny < 0 || ny >= room.size())
			continue;
		if (room[ny][nx] != 'P')
			continue;
		if (room[y + ddy[i]][x + ddx[i]] != 'X')
			return true;

	}
	for (int i = 0; i < 4; i++)//사람간의 거리가 대각선인 경우
	{
		int nx = x + dlx[i];
		int ny = y + dly[i];
		if (nx < 0 || nx >= room[0].size() || ny < 0 || ny >= room.size())
			continue;
		if (room[ny][nx] != 'P')
			continue;
		if (!(room[y][nx] == 'X'&&room[ny][x] == 'X'))
			return true;
	}
	return false;
}

int checkRoom(vector<string> v) {
	int num = 0;
	room = v;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if (v[i][j] == 'P')
			{
				if (checkPerson(j, i))
					return 0;
			}
		}
	}
	return 1;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	for (int i = 0; i < places.size(); i++)
	{
		answer.push_back(checkRoom(places[i]));
	}
	return answer;
}