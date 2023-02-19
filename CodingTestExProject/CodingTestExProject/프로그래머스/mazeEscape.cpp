/*
미로 탈출
https://school.programmers.co.kr/learn/courses/30/lessons/159993

bfs + 중간 지점
x,y 반대로 진행했는데 예제는 다 정사각형이라 처음부터 맞을 줄 알았다 해당 유형 풀때마다 순서 유의하기
*/
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int visited[105][105] = {0};
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int H = 0,W = 0;
int answer = -1;

void bfs(vector<string>& maps,int x,int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[y][x] = 1;
    // 래버 탐색 여부와 미로 탈출 최소시간
    bool isLeverFound = false;
    int minTime = 0;
    
    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if(maps[cy][cx]=='L') // 래버에 도달한 경우
        {
            minTime = visited[cy][cx];
            isLeverFound = true;

            memset(visited,0,sizeof(visited)); // 기존 거리 초기화 및 queue 비우기
            visited[cy][cx] = 1;
            q = queue<pair<int,int>>();
        }
        
        if(isLeverFound && maps[cy][cx]=='E') // 목적지에 도달한 경우 탐색 종료
        {
            answer = minTime + visited[cy][cx] - 2; // visited 시작이 언제나 1부터 시작하므로 거리에서 -2
            return;
        }
        
        for(int i = 0;i<4;i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx<0||ny<0||nx>=W||ny>=H)
                continue;
            
            if(visited[ny][nx]!=0)
                continue;
            
            if(maps[ny][nx]=='X')
                continue;
            
            q.push({nx,ny});
            visited[ny][nx] = visited[cy][cx] + 1;
        }
        
    }
}

int solution(vector<string> maps) {
    H = maps.size(); W = maps[0].size();
    for(int i = 0;i<H;i++)
    {
        for(int j = 0;j<W;j++)
        {
            if(maps[i][j]=='S')
            {
                bfs(maps,j,i);
            }
        }
    }
    return answer;
}