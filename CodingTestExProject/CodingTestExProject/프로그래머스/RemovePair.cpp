/*
* ¦���� �����ϱ�
* https://programmers.co.kr/learn/courses/30/lessons/12973
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