/*
* 디스크 컨트롤러 
* https://school.programmers.co.kr/learn/courses/30/lessons/42627?itm_content=course14743
* 
* 우선순위 큐를 사용하여 푸는 풀이
* 기존에는 우선순위 큐를 사용할때 구조체를 구현하여 내부 연산자를 오버로딩하는 방식으로 이 문제를 풀 수 있다.
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//cmp 구조체로 compare 구현 작업시간이 짧은 순으로 정렬되어야 함
struct compare {
    bool operator()(vector<int> a, vector<int> b)
    {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, compare> pq; // 소요시간 오름 차순 정렬

    int currentTime = 0;
    int cnt = 0;
    sort(jobs.begin(), jobs.end());
    //대기열이 없고 우선순위 큐가 빌때까지 반복하기
    while (cnt < jobs.size() || !pq.empty())
    {
        if (jobs.size() > cnt && currentTime >= jobs[cnt][0])
        {
            pq.push(jobs[cnt]);
            cnt++;
            continue;
        }
        // 큐가 비어있지 않다면
        if (!pq.empty())
        {
            currentTime += pq.top()[1];
            answer += (currentTime - pq.top()[0]);
            pq.pop();
        }
        else
        {
            currentTime = jobs[cnt][0];
        }
    }

    return answer / jobs.size();
}
//이전 풀이
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    bool isClear[501] = { 0, };
    vector<int> times;
    int minTime = 2e9; int startTime = 0;
    int T = jobs.size();
    sort(jobs.begin(), jobs.end());
    while (T--)
    {
        int elapsedTime = 0;
        minTime = 2e9;
        int index = 0;
        for (int i = 0; i < jobs.size(); i++)
        {
            if (isClear[i])
                continue;
            if (startTime < jobs[i][0])
                continue;
            elapsedTime = startTime + jobs[i][1] - jobs[i][0];
            if (minTime > elapsedTime)
            {
                index = i;
                minTime = elapsedTime;
            }
        }
        isClear[index] = true;
        startTime = jobs[index][0] + elapsedTime;
        times.push_back(elapsedTime);
    }
    for (int i = 0; i < times.size(); i++)
        answer += times[i];
    answer /= times.size();
    return answer;
}