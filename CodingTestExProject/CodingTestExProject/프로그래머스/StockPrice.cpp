/*
�ֽİ���
https://programmers.co.kr/learn/courses/30/lessons/42584

����for�� ���� �� �� �������� N^2�̶� ȿ���� ���� ������ �;��µ� ����Ǿ���.
����/ť ���� ������ �ٽ��ѹ� Ǯ��Ҵ�.
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++)
    {
        int time = 0;
        for (int j = i + 1; j < prices.size(); j++)
        {
            time++;
            if (prices[i] > prices[j])
                break;
        }
        answer.push_back(time);
    }
    return answer;
}

//���� Ǯ��
/*
* 
* �������� Ǯ����ٰ� �������� �� ���������ʾƼ� �ٸ� ����� Ȯ���غ��� ������ ��ܰ��� ������ �ε����� Ȱ���� ������ Ǫ�� ���̵� Ȯ���� �� �־���. 
Ǯ�� ���� : https://ssocoit.tistory.com/15 
�ٸ� ��� Ǯ�� ù ��� 
*/
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    for (int i = 0; i < prices.size(); i++)
    {
        while (!s.empty())
        {
            if (prices[s.top()] <= prices[i])//������ ���� ���� ��� ���
                break;
            answer[s.top()] = i - s.top();//������ �پ�� ���
            s.pop();
        }
        s.push(i);//���� i���� ���ÿ� ����
    }
    while (!s.empty())
    {
        answer[s.top()] = prices.size() - s.top() - 1;//���� - ��� �ð��� ���� �־��ش�.
        s.pop();
    }
    return answer;
}