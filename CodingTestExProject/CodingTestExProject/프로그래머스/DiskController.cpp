/*
* ��ũ ��Ʈ�ѷ� 
* https://school.programmers.co.kr/learn/courses/30/lessons/42627?itm_content=course14743
* 
* �켱���� ť�� ����Ͽ� Ǫ�� Ǯ��
* �������� �켱���� ť�� ����Ҷ� ����ü�� �����Ͽ� ���� �����ڸ� �����ε��ϴ� ������� �� ������ Ǯ �� �ִ�.
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//cmp ����ü�� compare ���� �۾��ð��� ª�� ������ ���ĵǾ�� ��
struct compare {
    bool operator()(vector<int> a, vector<int> b)
    {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, compare> pq; // �ҿ�ð� ���� ���� ����

    int currentTime = 0;
    int cnt = 0;
    sort(jobs.begin(), jobs.end());
    //��⿭�� ���� �켱���� ť�� �������� �ݺ��ϱ�
    while (cnt < jobs.size() || !pq.empty())
    {
        if (jobs.size() > cnt && currentTime >= jobs[cnt][0])
        {
            pq.push(jobs[cnt]);
            cnt++;
            continue;
        }
        // ť�� ������� �ʴٸ�
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
//���� Ǯ��
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