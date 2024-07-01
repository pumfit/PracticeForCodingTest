/*
https://school.programmers.co.kr/learn/courses/30/lessons/172928
*/
#include <string>
#include <vector>

using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int GetDirection(char s)
{
    if(s == 'N')
        return 0;
    if(s == 'S')
        return 1;
    if(s == 'W')
        return 2;
    if(s == 'E')
        return 3;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int cx = -1;
    int cy = -1;
    
    for(int y = 0; y<park.size(); y++)
    {
        for(int x = 0; x<park[0].size(); x++)
        {
            if(park[y][x]=='S')
            {
                cx = x; cy = y;
                break;
            }
        }
        if(cx != -1 || cy != -1)
            break;
    }

    for(int i = 0; i<routes.size(); i++)
    {
        string command = routes[i];
        int idx = GetDirection(command[0]);
        int count = command[2] - '0';

        int nx = cx; int ny = cy;
        
        while(count--)
        {
            nx = nx + dx[idx];
            ny = ny + dy[idx];
                
            if(nx<0||ny<0||nx>=park[0].size()||ny>=park.size())
                break;
            
            if(park[ny][nx]=='X')
                break;
                
            if(count == 0)
            {
                cx = nx;
                cy = ny;
            }
        }
    }

    answer.push_back(cy);
    answer.push_back(cx);
    
    return answer;
}