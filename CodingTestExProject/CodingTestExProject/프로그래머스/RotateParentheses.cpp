/*
* 괄호 회전하기
* https://school.programmers.co.kr/learn/courses/30/lessons/76502#qna
* 
* 괄호 스택문제인데 괄호 종류 세개인 점만 제외하면 된다. {([)}] 와 같은 경우에 괄호가 설립되지 않음을 스택을 통해 쉽게 파악할 수 있다.
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