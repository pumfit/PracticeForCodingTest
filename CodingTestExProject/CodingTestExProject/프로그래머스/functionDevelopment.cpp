/*
��� ����

https://programmers.co.kr/learn/courses/30/lessons/42586

�ҿ�ð��� �������� ���ϰ� ���ÿ� ���� �ڿ� ������ ������� �ߴ� ť�� ������ �Ǵµ�
ó�� ������ �������� �ع����� �������� �����ߴ�.
*/
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> s;
    //�ҿ�ð� ���ϱ�
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