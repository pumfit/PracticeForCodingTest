/*
올바른 괄호
https://school.programmers.co.kr/learn/courses/30/lessons/12909
*/
#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<int> correct;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            correct.push(1);
        }
        else
        {
            if (correct.empty())
            {
                return false;
            }
            else {
                correct.pop();
            }
        }
    }
    if (!correct.empty())
        return false;
    return true;
}