/*
바탕화면 정리
https://school.programmers.co.kr/learn/courses/30/lessons/161990
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    pair<int,int> firstPos = {wallpaper.size(),wallpaper[0].size()};
    pair<int,int> secondPos;
    for(int y = 0;y<wallpaper.size();y++)
    {
        for(int x = 0;x<wallpaper[y].size();x++)
        {
            if(wallpaper[y][x]=='#')
            {
                firstPos.first = min(firstPos.first,y);
                firstPos.second = min(firstPos.second,x);
                secondPos.first = max(secondPos.first,y+1);
                secondPos.second = max(secondPos.second,x+1);               
            }
        }
    }
    answer.push_back(firstPos.first);
    answer.push_back(firstPos.second);
    answer.push_back(secondPos.first);
    answer.push_back(secondPos.second);
    return answer;
}