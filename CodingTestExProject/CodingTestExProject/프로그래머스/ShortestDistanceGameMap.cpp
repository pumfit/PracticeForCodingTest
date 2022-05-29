/*
게임 맵 최단거리

찾아라 프로그래밍 마에스터
https://programmers.co.kr/learn/courses/30/lessons/1844

그냥 기본BFS문제
*/
#include<vector>
#include<queue>
using namespace std;

int visited[101][101] = { 0, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int Y = 0;
int X = 0;

void BFS(vector<vector<int>>& map)
{
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    visited[0][0] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= X | ny >= Y)
                continue;
            if (visited[ny][nx])
                continue;
            if (map[ny][nx] == 1)
            {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ nx,ny });
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{
    Y = maps.size(); X = maps[0].size();
    int answer = 0;
    BFS(maps);
    return visited[Y - 1][X - 1] == 0 ? -1 : visited[Y - 1][X - 1];
}