/*
��Ʈ��ũ

https://school.programmers.co.kr/learn/courses/30/lessons/43162

�⺻���� dfs(�Ǵ� bfs) ����

���õǴ� ������ �ٸ��������� ���õǴ� i,j,value ���� ���ܼ� �׷����� ������ٰ� ���ϱ� n��ŭ�� ���̸� ���� �ִ��� ���� �� ǥ���� ����������.
�׷��� �����ߴ� ��� �ѹ� Ǯ�� �־��� ��� �ѹ� Ǯ����.
�ι�° Ǯ���� ��� ������ n���� ���� �ִ� �� ���� ���� �Ǵ��ϴ� ������ �ǰ� i�� ���� ����� �ε����� �ȴٴ� �������� �ִ�.
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
//��ȯ���� Ǫ�� Ǯ��
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