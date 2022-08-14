/*
«¡∏∞≈Õ

https://school.programmers.co.kr/learn/courses/30/lessons/42587

*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int num = priorities[location];
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++)
        pq.push(priorities[i]);
    for (int i = 0; i < priorities.size(); i++)
        q.push({ priorities[i],i });
    int i = 0;
    while (!pq.empty())
    {
        int topPriority = pq.top();
        pq.pop();
        while (topPriority != q.front().first)
        {
            q.push(q.front());
            q.pop();
        }
        answer++;
        if (q.front().second == location)
            return answer;
        q.pop();
    }

    return -1;
}