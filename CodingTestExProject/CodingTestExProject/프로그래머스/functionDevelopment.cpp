/*
기능 개발

https://programmers.co.kr/learn/courses/30/lessons/42586

소요시간을 역순으로 구하고 스택에 넣은 뒤에 꺼내는 방식으로 했다 큐에 넣으면 되는데
처음 시작을 스택으로 해버려서 스택으로 진행했다.
*/
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> s;
    //소요시간 구하기
    for (int i = progresses.size() - 1; i >= 0; i--)
    {
        int days = (100 - progresses[i]) % speeds[i] > 0 ? (100 - progresses[i]) / speeds[i] + 1 : (100 - progresses[i]) / speeds[i];
        s.push(days);
    }
 
    while (!s.empty())
    {
        int n = s.top();
        int cnt = 1;
        s.pop();
        if (s.empty())
        {
            answer.push_back(cnt);
            break;
        }
        while (s.top() <= n)
        {
            s.pop();
            cnt++;
            if (s.empty())
                break;
        }
        answer.push_back(cnt);

    }
    return answer;
}