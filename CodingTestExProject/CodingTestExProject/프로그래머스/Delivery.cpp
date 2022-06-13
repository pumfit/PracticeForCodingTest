/*
배달
https://programmers.co.kr/learn/courses/30/lessons/12978

양방향 그래프, 최소 시간(거리)
"N개의 마을 중에서 K 시간 이하로 배달이 가능한 마을에서만 주문을 받으려고 합니다."
거리가 시간으로 표현되어 있으므로 최단 거리 알고리즘을 사용하면 되는 문제

이 문제는 다익스트라로 풀 수 있는 기본 문제
우선순위큐를 사용하는 다익스트라로 기본적인 구현은 검색을 참고해서 진행했다.

코드 참고 : https://hub1234.tistory.com/33
다익스트라 정리 : https://www.notion.so/1-42241c67ad6f40ceb037ea8408438fc7
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
    priority_queue<pair<int, int>> pq;//현재 거리 , 현재 노드

    pq.push({ 0,s });
    minTime[s] = 0;

    while (!pq.empty())
    {
        int cost = -pq.top().first;//비용
        int cur = pq.top().second;
        pq.pop();

        if (minTime[cur] < cost)
            continue;

        for (int i = 0; i < town[cur].size(); i++)
        {
            int curCost = cost + town[cur][i].second;

            if (curCost < minTime[town[cur][i].first])//적은 비용
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
        town[road[i][1]].push_back({ road[i][0],road[i][2] });//양방향 그래프
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