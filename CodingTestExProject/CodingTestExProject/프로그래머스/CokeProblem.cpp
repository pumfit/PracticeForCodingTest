/*
콜라문제

https://school.programmers.co.kr/learn/courses/30/lessons/132267

*/
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n >= a)
    {
        int cnt = 0;
        while (n >= a)
        {
            n -= a;
            cnt += b;
        }
        n += cnt;
        answer += cnt;
    }

    return answer;
}