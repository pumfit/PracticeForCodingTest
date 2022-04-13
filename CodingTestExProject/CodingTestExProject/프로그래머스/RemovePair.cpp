/*
* 짝지어 제거하기
* https://programmers.co.kr/learn/courses/30/lessons/12973
* 
* 짝을 지어서 제거 하므로 괄호 문제들을 생각해 볼 수 있다.
* 스택을 사용하는 자료구조 문제
* 넣어줄 문자와 스택 맨 위의 문자가 동일하다면 빼주고 아니라면 넣어주어 마지막의 스택의 길이를 확인해주면 된다.
* 다만 처음에 풀때 string substr로 풀었었는데 이경우에는 효율성이 0 이 나온다.
* 
채점 결과
정확성: 60.2
효율성: 0.0
합계: 60.2 / 100.0
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
채점 결과
정확성: 60.2
효율성: 39.8
합계: 100.0 / 100.0
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