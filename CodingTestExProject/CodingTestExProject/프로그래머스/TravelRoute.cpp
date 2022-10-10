/*
���� ���
https://school.programmers.co.kr/learn/courses/30/lessons/43164

�ܾ� ��ȯ�ϰ� ������ ����

��� ��θ� ������ ���� ���ΰ�?

���� ���� ���� ������ ��� ���ĺ� ������ ��ȯ�ؾ��ϴµ�
�̴� ���� ��θ� ���ѵ� ���ϴ� ���� �ƴ϶� ó���� Ƽ�� ������ ���� �����صθ� ó�� ���� ��ΰ� ���ĺ� ������ ���� ���� ��ΰ� �ȴ�.

������ ���� 1,2 ������ Ʋ�Ⱦ��µ� ���� ������ �ʴ� ��쿡
�ʹݿ� �߰��صξ��� ICN�� �����־ ����. �������� pop_back���� �ش簪�� ���ָ� ���� 1,2���� ��� ����Ѵ�.

��� �������� ���� ó���ؾ��ϳ��� ����ϴ� ������ �𸣰ھ ã�ƺôµ� �������� �����߰�
������ bt �� ��ȯ ������ �򰥸��� �� ���Ƽ� N�� M ������ �����ؾ��� �� ����.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool visited[5001] = { 0, };

bool FindPath(int depth, string city, vector<string>& v, vector<vector<string>>& tickets)
{
    v.push_back(city);

    if (depth == tickets.size())
    {
        return true;
    }

    for (int i = 0; i < tickets.size(); i++)
    {
        if (visited[i])
            continue;
        if (city == tickets[i][0])
        {
            visited[i] = 1;
            bool isClear = FindPath(depth + 1, tickets[i][1], v, tickets);
            if (isClear)
                return true;
            visited[i] = 0;
        }
    }
    v.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    FindPath(0, "ICN", answer, tickets);
    return answer;

}