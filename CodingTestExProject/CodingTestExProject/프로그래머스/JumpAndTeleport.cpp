/*
https://programmers.co.kr/learn/courses/30/lessons/12980

처음에 백트래킹인가 DP인가 했는데 N이 10억이라길래 포기했다.
값자체에서 답을 찾는 방식을 고민했고
이전 값의 2배가 되므로 결과값이 될때까지 2배가 진행되면 되고 홀수 인경우엔 1을 더하는 방식으로 진행하면 된다.
처음엔 고민 많이했는데 생각보다 쉽게 풀려서 당황스러웠던 문제
*/
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans++;
        }
        n /= 2;
    }
    return ans;
}