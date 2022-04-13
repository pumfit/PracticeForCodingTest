/*
* ¦���� �����ϱ�
* https://programmers.co.kr/learn/courses/30/lessons/12973
* 
* ¦�� ��� ���� �ϹǷ� ��ȣ �������� ������ �� �� �ִ�.
* ������ ����ϴ� �ڷᱸ�� ����
* �־��� ���ڿ� ���� �� ���� ���ڰ� �����ϴٸ� ���ְ� �ƴ϶�� �־��־� �������� ������ ���̸� Ȯ�����ָ� �ȴ�.
* �ٸ� ó���� Ǯ�� string substr�� Ǯ�����µ� �̰�쿡�� ȿ������ 0 �� ���´�.
* 
ä�� ���
��Ȯ��: 60.2
ȿ����: 0.0
�հ�: 60.2 / 100.0
*/
#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    int answer = -1;
    while (s.size() > 0)
    {
        bool isFind = false;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                string s1 = s.substr(0, i);
                string s2 = s.substr(i + 2, s.size() - 2 - i);
                s = s1 + s2;
                isFind = true;
                break;
            }
        }
        if (!isFind)
        {
            answer = 0;
            break;
        }
    }
    if (s.size() == 0)
        answer = 1;
    return answer;
}
/*
*
ä�� ���
��Ȯ��: 60.2
ȿ����: 39.8
�հ�: 100.0 / 100.0
* /
#include <iostream>
#include <stack>
#include<string>
using namespace std;

int solution(string str)
{
    int answer = -1;
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        if (!s.empty() && s.top() == str[i])
        {
            s.pop();

        }
        else
        {
            s.push(str[i]);
        }
    }
    if (s.size() == 0)
        answer = 1;
    else
        answer = 0;

    return answer;
}