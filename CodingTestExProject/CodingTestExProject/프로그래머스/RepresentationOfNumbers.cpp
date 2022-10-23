/*
 표현

https://school.programmers.co.kr/learn/courses/30/lessons/12924

슬라이딩 윈도우로 풀이한 숫자의 표현이다.
n이 주어지면 n이 만들어질 수 있는 모든 연속하는 합을 구하면 된다.

*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//슬라이딩 윈도우 
int solution(int n) {
    int answer = 0;
    int sum = 0;
    for (int left = 1; left <= n; left++)
    {
        sum = 0;
        for (int right = left; right <= n; right++)
        {
            sum += right;
            if (sum == n)
            {
                answer++;
            }
            if (sum >= n)
                break;
        }
    }
    return answer;
}