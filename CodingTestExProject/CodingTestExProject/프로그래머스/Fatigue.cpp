/*
* �Ƿε�
https://programmers.co.kr/learn/courses/30/lessons/87946

N�� 8���ϱ淡 ��üŽ���� �����ϰڴ� �����߰�
ó���� BT�� Ǯ��߰ڴ� �����ߴ�. ���� BT������ return ������ ���� �����ؼ�
dfs�� for�� ���� �ִ밪�� ���信 �־��ִ� ����� ����ϸ� �ȴ�.

dfs���� cnt+1�ϴ� �κ��� ������ ���� �Ǽ��� �ؼ� cnt���� ���� �ʾ� ���� �ɷȰ�
dungeons�� �Ű������� �����ʰ� ���� ���δ°� ���� �� ����.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N = 0;
int answer = -1;
int visited[8] = { 0, };

void dfs(int curHp, int cnt, vector<vector<int>> dungeons)
{
    for (int i = 0; i < N; i++)
    {
        if (curHp < dungeons[i][0])
            continue;
        if (!visited[i])
        {
            visited[i] = 1;
            dfs(curHp - dungeons[i][1], cnt + 1, dungeons);
            visited[i] = 0;
        }
    }
    answer = max(answer, cnt);
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    N = dungeons.size();
    sort(dungeons.begin(), dungeons.end());
    dfs(k, 0, dungeons);
    return answer;
}