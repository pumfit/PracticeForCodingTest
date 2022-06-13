/*
���
https://programmers.co.kr/learn/courses/30/lessons/12978

����� �׷���, �ּ� �ð�(�Ÿ�)
"N���� ���� �߿��� K �ð� ���Ϸ� ����� ������ ���������� �ֹ��� �������� �մϴ�."
�Ÿ��� �ð����� ǥ���Ǿ� �����Ƿ� �ִ� �Ÿ� �˰����� ����ϸ� �Ǵ� ����

�� ������ ���ͽ�Ʈ��� Ǯ �� �ִ� �⺻ ����
�켱����ť�� ����ϴ� ���ͽ�Ʈ��� �⺻���� ������ �˻��� �����ؼ� �����ߴ�.

�ڵ� ���� : https://hub1234.tistory.com/33
���ͽ�Ʈ�� ���� : https://www.notion.so/1-42241c67ad6f40ceb037ea8408438fc7
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9

vector<pair<int, int>> town[51];
int minTime[51];

void Dijkstra(int s)
{
    priority_queue<pair<int, int>> pq;//���� �Ÿ� , ���� ���

    pq.push({ 0,s });
    minTime[s] = 0;

    while (!pq.empty())
    {
        int cost = -pq.top().first;//���
        int cur = pq.top().second;
        pq.pop();

        if (minTime[cur] < cost)
            continue;

        for (int i = 0; i < town[cur].size(); i++)
        {
            int curCost = cost + town[cur][i].second;

            if (curCost < minTime[town[cur][i].first])//���� ���
            {
                minTime[town[cur][i].first] = curCost;
                pq.push({ -curCost,town[cur][i].first });
            }
        }
    }

}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for (int i = 0; i < road.size(); i++)
    {
        town[road[i][0]].push_back({ road[i][1],road[i][2] });
        town[road[i][1]].push_back({ road[i][0],road[i][2] });//����� �׷���
    }

    fill(minTime, minTime + 51, INF);

    Dijkstra(1);

    for (int i = 1; i <= N; i++)
    {
        cout << minTime[i] << endl;
        if (minTime[i] <= K)
            answer++;
    }
    return answer;
}