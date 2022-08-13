/*
* 약수의 개수와 덧셈
* https://school.programmers.co.kr/learn/courses/30/lessons/77884#
테케 1번 n == 1일때 값 1 리턴해줘야함
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int FindDivisorNumber(int n)
{
    if (n == 1)
        return 1;
    int cnt = 2;
    for (int i = 2; i * i <= n; i++)
    {
        if (i * i == n)
        {
            cnt++;
        }
        else if (n % i == 0)
        {
            cnt += 2;
        }
    }
    return cnt;
}

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++)
    {
        if (FindDivisorNumber(i) % 2 == 0)
            answer += i;
        else
            answer -= i;
    }
    return answer;
}