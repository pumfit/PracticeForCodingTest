/*
대충 만든 자판
https://school.programmers.co.kr/learn/courses/30/lessons/160586

자판 입력이 최소가되도록 변경해주면된다. 몇번 자판인지는 상관이 없는 문제인데 처음에 자판별로 들어가는 줄 알고 pair를 사용했다.

*/
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer = vector<int> (targets.size());
    map<char,pair<int,int>> m;
    for(int i = 0;i<keymap.size();i++)
    {
        for(int j = 0;j<keymap[i].size();j++)
        {
            if(m[keymap[i][j]].second==0)
            {
                m[keymap[i][j]] = {i,j+1};
            }
            else if(m[keymap[i][j]].second>j+1){
                m[keymap[i][j]] = {i,j+1};
            }
        }
    }
    for(int i = 0;i<targets.size();i++)
    {
        for(int j = 0;j<targets[i].size();j++)
        {
            if(m[targets[i][j]].second==0)
            {
                answer[i] = -1;
                break;
            }
            answer[i] += m[targets[i][j]].second;  
        }
    }
    return answer;
}