/*
3진법 뒤집기
https://school.programmers.co.kr/learn/courses/30/lessons/68935
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int ChangeNumber(int n)
{
    string s = "";
    while (n > 0)
    {
        s += (n % 3) + '0';
        n /= 3;
    }
    int sum = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {

        if (s[i] == '0')
            continue;
        if (s[i] == '1')
        {
            int n = 1;
            for (int j = 0; j < s.size() - i - 1; j++)
            {
                n *= 3;
            }
            sum += n;
        }
        else if (s[i] == '2')
        {
            int n = 2;
            for (int j = 0; j < s.size() - 1 - i; j++)
            {
                n *= 3;
            }
            sum += n;
        }
    }
    return sum;
}

int solution(int n) {
    int answer = 0;
    return ChangeNumber(n);
}