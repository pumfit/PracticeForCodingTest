/*
네트워크

https://school.programmers.co.kr/learn/courses/30/lessons/43162

기본적인 dfs(또는 bfs) 문제

제시되는 정보가 다른문제에서 제시되는 i,j,value 같이 생겨서 그래프로 만들었다가 보니까 n만큼의 길이를 갈수 있는지 없는 지 표시한 문제였었다.
그래서 진행했던 대로 한번 풀고 주어진 대로 한번 풀었다.
두번째 풀이의 경우 기존의 n값이 갈수 있는 지 없는 지를 판단하는 기준이 되고 i가 다음 노드의 인덱스가 된다는 차이점이 있다.
*/
#include <string>
#include <vector>

using namespace std;

bool visited[201] = { 0, };
vector<int> v[201];

void dfs(int s)
{
    visited[s] = 1;
    for (int i = 0; i < v[s].size(); i++)
    {
        int n = v[s][i];
        if (visited[n])
            continue;
        dfs(n);
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (computers[i][j] == 0)
                continue;
            v[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            answer++;
        }
    }
    return answer;
}
//변환없이 푸는 풀이
#include <string>
#include <vector>

using namespace std;

bool visited[201] = { 0, };
vector<int> v[201];
int computerNum = 0;

void dfs(int s, vector<vector<int>>& computers)
{
    visited[s] = 1;
    for (int i = 0; i < computerNum; i++)
    {
        int n = computers[s][i];
        if (n == 0)
            continue;
        if (visited[i])
            continue;
        dfs(i, computers);
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    computerNum = n;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, computers);
            answer++;
        }
    }
    return answer;
}