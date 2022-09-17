/*
예상 대진표
https://school.programmers.co.kr/learn/courses/30/lessons/12985

N은 왜 필요한건지 모르겠다
처음에 답을 1로 지정하고 두 값의 차이가 1이면 탈출하도록 조건을 주었더니 4개정도 테케가 틀렸다.
두 값의 차이 1일때 34 이렇게 되버리면 같은 조가 아님을 간과하고 풀었었다. 그러고 보니 한단계 더들어가면 두 값이 같이지고 이렇게 처리하면 굳이 초기 answer값을 1로 설정하지 않아도 되겠다 싶어서
변경하고 제출해보았더니 모두 통과하였다.
*/
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    while (true)
    {
        if (a == b)
            break;
        a = a % 2 == 0 ? a / 2 : a / 2 + 1;
        b = b % 2 == 0 ? b / 2 : b / 2 + 1;
        answer++;
    }

    return answer;
}