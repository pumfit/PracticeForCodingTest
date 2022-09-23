/*
* ��ȣ ȸ���ϱ�
* https://school.programmers.co.kr/learn/courses/30/lessons/76502#qna
* 
* ��ȣ ���ù����ε� ��ȣ ���� ������ ���� �����ϸ� �ȴ�. {([)}] �� ���� ��쿡 ��ȣ�� �������� ������ ������ ���� ���� �ľ��� �� �ִ�.
*/
#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

bool CheckIsCurrect(string str, int index, int size)
{
    stack<char> s;
    for (int i = index; i < index + size; i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else if (str[i] == '}')
        {
            if (s.empty())
                return false;
            if (s.top() == '{')
            {
                s.pop();
            }
        }
        else if (str[i] == ')')
        {
            if (s.empty())
                return false;
            if (s.top() == '(')
            {
                s.pop();
            }
        }
        else if (str[i] == ']')
        {
            if (s.empty())
                return false;
            if (s.top() == '[')
            {
                s.pop();
            }
        }
    }
    return s.empty() ? true : false;

}

int solution(string s) {
    int answer = 0;
    string ss = s + s;
    int length = s.size();
    for (int i = 0; i < length; i++)
    {
        if (CheckIsCurrect(ss, i, length))
        {
            answer++;
        }
    }
    return answer;
}